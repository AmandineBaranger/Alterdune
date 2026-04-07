//
// Created by Amandine Baranger on 06/04/2026.
//
#include "jeu.h"
#include <fstream>
#include <sstream>


#include "boss.h"
#include "item.h"
#include "miniboss.h"
#include "monstrenormal.h"

using namespace std;

Jeu::Jeu() {
    catalogueActions["COMPLIMENT"] = ActionAct("COMPLIMENT", "Tu dis au monstre qu'il a de beaux yeux.", 20);
    catalogueActions["JOKE"] = ActionAct("JOKE", "Tu racontes une blague absurde sur les frites.", 15);
    catalogueActions["INSULT"] = ActionAct("INSULT", "Tu te moques de sa mere. Il n'apprecie pas !", -20);
}

Jeu::~Jeu() {
    for (Monstre* m : baseMonstres) {
        delete m;
    }
    baseMonstres.clear();
}
void Jeu::chargerFichiers() { // Sans argument, comme dans l'UML !
    ifstream fichierMonstres("monstres.csv");

    if (!fichierMonstres.is_open()) {
        cout << "Erreur : fichier monsters.csv introuvable. Arret du jeu." << endl;
        exit(1);
    }

    string ligne;
    while (getline(fichierMonstres, ligne)) {
        if (ligne.empty()) continue;

        stringstream ss(ligne);
        string cat, nom, hpStr, atkStr, defStr, mercyStr;

        getline(ss, cat, ';');
        getline(ss, nom, ';');
        getline(ss, hpStr, ';');
        getline(ss, atkStr, ';');
        getline(ss, defStr, ';');
        getline(ss, mercyStr, ';');

        try {
            int hp = stoi(hpStr);
            int atk = stoi(atkStr);
            int def = stoi(defStr);
            int mercy = stoi(mercyStr);

            if (cat == "NORMAL") {
                baseMonstres.push_back(new MonstreNormal(nom, hp, atk, def, mercy));
            } else if (cat == "MINIBOSS") {
                baseMonstres.push_back(new Miniboss(nom, hp, atk, def, mercy));
            } else if (cat == "BOSS") {
                baseMonstres.push_back(new Boss(nom, hp, atk, def, mercy));
            }
        } catch (...) {
            continue;
        }
    }
    fichierMonstres.close();
    cout << "Base de donnees des monstres chargee." << endl;
}


void Jeu::demarrer() {
    chargerFichiers();

    cout << "\n=== BIENVENUE DANS ALTERDUNE ===" << endl;
    cout << "Saisissez le nom de votre personnage : ";
    string nom;
    cin >> nom;

    Joueur joueurPrincipal(nom, 50);

    int choix = 0;
    while (choix != 3 && joueurPrincipal.estVivant()) {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Voir le profil de " << joueurPrincipal.getNom() << endl;
        cout << "2. Lancer un combat test" << endl;
        cout << "3. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        if (choix == 1) {
            cout << "\n-- STATS --" << endl;
            cout << "HP : " << joueurPrincipal.getHpActuel() << " / " << joueurPrincipal.getHpMax() << endl;
            cout << "Victoires : " << joueurPrincipal.getVictoires() << endl;
        }
        else if (choix == 2) {
            if (!baseMonstres.empty()) {
                boucleCombat(joueurPrincipal, baseMonstres[0]);
                verifierFinDePartie(joueurPrincipal);
            } else {
                cout << "Erreur : Aucun monstre disponible." << endl;
            }
        }
    }
    cout << "Merci d'avoir joue a Alterdune !" << endl;
}

void Jeu::boucleCombat(Joueur& j, Monstre* m) {
    cout << "Un combat commence contre " << m->getNom() << " !" << endl;
}

void Jeu::verifierFinDePartie(Joueur& j) {
    if (j.getVictoires() >= 10) {
        cout << "Fin de la partie atteinte !" << endl;
    }
}