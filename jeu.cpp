//
// Created by Amandine Baranger on 06/04/2026.
//
#include "jeu.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "boss.h"
#include "item.h"
#include "miniboss.h"
#include "monstrenormal.h"

using namespace std;

Jeu::Jeu() {
    // Initialisation du catalogue des actions pré-définies
    catalogueActions["COMPLIMENT"] = ActionAct("COMPLIMENT", "Tu dis au monstre qu'il a de beaux yeux.", 20);
    catalogueActions["JOKE"] = ActionAct("JOKE", "Tu racontes une blague absurde sur les frites.", 15);
    catalogueActions["INSULT"] = ActionAct("INSULT", "Tu te moques de sa mere. Il n'apprecie pas !", -20);
    catalogueActions["DANCE"] = ActionAct("DANCE", "Tu entames une danse de la pluie. Le monstre est confus.", 10);
    catalogueActions["OBSERVE"] = ActionAct("OBSERVE", "Tu observes attentivement le monstre, il semble intrigué.", 15);
    catalogueActions["PET"] = ActionAct("PET", "Tu caresses doucement le monstre. Il ronronne presque.", 25);
    catalogueActions["OFFER_SNACK"] = ActionAct("OFFER_SNACK", "Tu lui offres une collation. Il accepte avec gratitude.", 30);
    catalogueActions["DISCUSS"] = ActionAct("DISCUSS", "Vous discutez de la vie, de l'univers et du reste.", 20);
    catalogueActions["REASON"] = ActionAct("REASON", "Tu tentes de raisonner le monstre avec logique.", 18);
    catalogueActions["TAUNT"] = ActionAct("TAUNT", "Tu provoque ouvertement le monstre. Il s'énerve fortement.", -25);
}

Jeu::~Jeu() {
    // Libération de la mémoire allouée dynamiquement pour éviter les fuites (memory leaks)
    for (Monstre* m : baseMonstres) {
        delete m;
    }
    baseMonstres.clear();
}

void Jeu::chargerFichiers() {
    ifstream fichierMonstres("monstres.csv"); 

    if (!fichierMonstres.is_open()) {
        cerr << "Erreur : fichier monstres.csv introuvable. Arret du programme." << endl;
        exit(1);
    }

    string ligne;
    // On ignore la première ligne si c'est l'en-tête (categorie;nom;hp;atk;def...)
    // getline(fichierMonstres, ligne); // Décommente cette ligne si ton CSV a un en-tête !

    while (getline(fichierMonstres, ligne)) {
        if (ligne.empty()) continue; // Ignorer les lignes vides potentielles

        stringstream ss(ligne);
        string cat, nom, hpStr, atkStr, defStr, mercyStr, a1, a2, a3, a4;

        // Parsing des 10 colonnes séparées par des points-virgules
        getline(ss, cat, ';');
        getline(ss, nom, ';');
        getline(ss, hpStr, ';');
        getline(ss, atkStr, ';');
        getline(ss, defStr, ';');
        getline(ss, mercyStr, ';');
        getline(ss, a1, ';'); // Action 1
        getline(ss, a2, ';'); // Action 2
        getline(ss, a3, ';'); // Action 3

        // Pour la dernière colonne, on prend jusqu'à la fin de la ligne (pas de ';')
        getline(ss, a4);

        // Nettoyage d'un éventuel retour chariot (\r) invisible à la fin de a4 (fréquent sous Windows)
        if (!a4.empty() && a4.back() == '\r') {
            a4.pop_back();
        }

        try {
            // Conversion des chaînes de caractères en entiers
            int hp = stoi(hpStr);
            int atk = stoi(atkStr);
            int def = stoi(defStr);
            int mercy = stoi(mercyStr);

            // Instanciation polymorphique AVEC les 4 nouvelles actions
            if (cat == "NORMAL") {
                baseMonstres.push_back(new MonstreNormal(nom, hp, atk, def, mercy, a1, a2, a3, a4));
            } else if (cat == "MINIBOSS") {
                baseMonstres.push_back(new Miniboss(nom, hp, atk, def, mercy, a1, a2, a3, a4));
            } else if (cat == "BOSS") {
                baseMonstres.push_back(new Boss(nom, hp, atk, def, mercy, a1, a2, a3, a4));
            }
        } catch (...) {
            // En cas de ligne mal formée (stoi échoue ou en-tête lu par erreur), on ignore
            continue;
        }
    }
    fichierMonstres.close();
    cout << "Base de donnees des monstres chargee avec succes." << endl;
}

void Jeu::demarrer() {
    // Initialisation de la graine pour la génération pseudo-aléatoire (utilisée pour les dégâts)
    srand(time(NULL));
    chargerFichiers();

    cout << "\n=== BIENVENUE DANS ALTERDUNE ===" << endl;
    cout << "Saisissez le nom de votre personnage : ";
    string nom;
    cin >> nom;

    // Création de l'instance du joueur pour la session
    Joueur joueurPrincipal(nom, 50);

    // Parsing du fichier d'inventaire initial
    ifstream fichierItems("items.csv");
    if (fichierItems.is_open()) {
        string ligneItem;
        while (getline(fichierItems, ligneItem)) {
            if (ligneItem.empty()) continue;
            stringstream ss(ligneItem);
            string nomI, typeI, valStr, qteStr;
            getline(ss, nomI, ';');
            getline(ss, typeI, ';');
            getline(ss, valStr, ';');
            getline(ss, qteStr, ';');
            try {
                // Instanciation de l'objet Item (à lier prochainement à la méthode ajouterItem du Joueur)
                joueurPrincipal.ajouterItem(Item(nomI, typeI, stoi(valStr), stoi(qteStr)));
            } catch(...) {}
        }
        fichierItems.close();
    }

    int choix = 0;
    // Boucle principale du programme : gestion du menu et des conditions d'arrêt
    while (choix != 5 && joueurPrincipal.estVivant() && joueurPrincipal.getVictoires() < 10) {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Bestiaire" << endl;
        cout << "2. Demarrer un combat" << endl;
        cout << "3. Statistiques du personnage" << endl;
        cout << "4. Items (Inventaire)" << endl;
        cout << "5. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        if (choix == 1) {
            cout << "\n-- BESTIAIRE --" << endl;
            joueurPrincipal.getBestiaire().afficher();
        }
        else if (choix == 2) {
            if (!baseMonstres.empty()) {
                // On tire un nombre au hasard entre 0 et la taille du bestiaire
                int indexAleatoire = rand() % baseMonstres.size();
                Monstre* monstreCible = baseMonstres[indexAleatoire];

                // On réinitialise ses PV pour qu'il soit tout neuf pour ce combat
                monstreCible->restaurerHp();

                // Lancement de l'affrontement
                boucleCombat(joueurPrincipal, monstreCible);
            } else {
                cerr << "Erreur critique : Vecteur d'ennemis vide." << endl;
            }
        }
        else if (choix == 3) {
            cout << "\n-- STATISTIQUES --" << endl;
            cout << "Nom : " << joueurPrincipal.getNom() << endl;
            cout << "HP : " << joueurPrincipal.getHpActuel() << " / " << joueurPrincipal.getHpMax() << endl;
            cout << "Monstres Tues : " << joueurPrincipal.getMonstresTues() << endl;
            cout << "Monstres Epargnes : " << joueurPrincipal.getMonstresEpargnes() << endl;
            cout << "Victoires : " << joueurPrincipal.getVictoires() << " / 10" << endl;
        }
        else if (choix == 4) {
            cout << "\n-- INVENTAIRE --" << endl;
            joueurPrincipal.afficherInventaire();

            cout << "\nEntrez le numero de l'objet a utiliser (ou 0 pour annuler) : ";
            int choixItem;
            cin >> choixItem;

            if (choixItem > 0) {
                // On fait -1 car le joueur tape 1, 2, 3... mais le vecteur commence à 0
                joueurPrincipal.utiliserItem(choixItem - 1);
            }
        }
    }

    // Évaluation des conditions de fin en sortie de boucle
    if (joueurPrincipal.getVictoires() >= 10) {
        verifierFinDePartie(joueurPrincipal);
    } else {
        cout << "\nFermeture du programme." << endl;
    }
}

void Jeu::boucleCombat(Joueur& j, Monstre* m) {
    cout << "\n=====================================" << endl;
    cout << "UN COMBAT COMMENCE CONTRE " << m->getNom() << " (" << m->getCategory() << ") !" << endl;
    cout << "=====================================\n" << endl;

    bool combatTermine = false;

    // Déroulement du combat en tour par tour
    while (j.estVivant() && m->estVivant() && !combatTermine) {
        cout << "\n--- TOUR DE " << j.getNom() << " ---" << endl;
        cout << "Vos HP: " << j.getHpActuel() << "/" << j.getHpMax() << " | Monstre HP: " << m->getHpActuel() << "/" << m->getHpMax() << endl;
        cout << "1. FIGHT (Attaquer)\n2. ACT (Agir)\n3. ITEM (Objets)\n4. MERCY (Epargner)\nChoix : ";

        int choix;
        cin >> choix;
        cout << endl;

        if (choix == 1) {
            j.attaquer(*m);
            if (!m->estVivant()) {
                combatTermine = true;
                j.getBestiaire().ajouterEntree(*m, "Tue");
            }
        }
        else if (choix == 2) {
            cout << "-- ACTIONS DISPONIBLES POUR " << m->getNom() << " --" << endl;

            // On affiche uniquement les actions qui ne sont pas des tirets "-"
            vector<string> choixValides;
            for (int i = 0; i < 4; i++) {
                if (m->getAction(i) != "-") {
                    cout << i + 1 << ". " << m->getAction(i) << endl;
                    choixValides.push_back(m->getAction(i));
                }
            }
            cout << "Choix : ";
            int numAct;
            cin >> numAct;

            if (numAct > 0 && numAct <= choixValides.size()) {
                string nomAction = choixValides[numAct - 1];

                // On vérifie si l'action existe dans notre catalogue
                if (catalogueActions.count(nomAction)) {
                    j.agirACT(*m, catalogueActions[nomAction]);
                } else {
                    // Si l'action est dans le CSV mais pas définie dans le catalogue C++
                    cout << "Vous essayez " << nomAction << " mais rien ne se passe..." << endl;
                }
            }
        }
        else if (choix == 3) {
            j.afficherInventaire();
            cout << "Entrez le numero de l'objet a utiliser (ou 0 pour annuler) : ";
            int choixItem;
            cin >> choixItem;

            if (choixItem > 0) {
                j.utiliserItem(choixItem - 1);
            } else {
                cout << "Vous refermez votre sac et passez a l'action." << endl;
            }
        }
        else if (choix == 4) {
            j.epargnerMercy(*m);
            if (m->peutEtreEpargne()) {
                combatTermine = true;
                j.getBestiaire().ajouterEntree(*m, "Epargne");
            }
        }
        else {
            cout << "Saisie invalide. Tour passe." << endl;
        }

        // Tour de l'adversaire si les conditions de poursuite du combat sont toujours réunies
        if (!combatTermine && m->estVivant()) {
            cout << "\n--- TOUR DU MONSTRE ---" << endl;
            m->attaquer(j);

            if (!j.estVivant()) {
                cout << "\nHP a zero. Echec de la simulation." << endl;
                combatTermine = true;
            }
        }
    }
}

void Jeu::verifierFinDePartie(Joueur& j) {
    cout << "\n=====================================" << endl;
    cout << "         FIN DE LA PARTIE !          " << endl;
    cout << "=====================================\n" << endl;

    // Récupération des statistiques pour déterminer l'une des trois fins requises
    int tues = j.getMonstresTues();
    int epargnes = j.getMonstresEpargnes();

    if (epargnes == 0 && tues > 0) {
        cout << "FIN GENOCIDAIRE : Tous les adversaires vaincus ont ete tues." << endl;
    }
    else if (tues == 0 && epargnes > 0) {
        cout << "FIN PACIFISTE : Tous les adversaires vaincus ont ete epargnes via le systeme Mercy." << endl;
    }
    else {
        cout << "FIN NEUTRE : Une approche mixte a ete adoptee (combinaison de victoires mortelles et pacifiques)." << endl;
    }
}