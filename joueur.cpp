//
// Created by Amandine Baranger on 05/04/2026.
//
#include "joueur.h"
#include "monstre.h"
#include "actionAct.h"
#include <iostream>

#include "bestiaire.h"

using namespace std;

Joueur::Joueur(string nomEntite, int hp) : Entite(nomEntite, hp) {
    monstresTues = 0;
    monstresEpargnes = 0;
    victoires = 0;
}

// Implémentation de l'attaque avec dégâts aléatoires
void Joueur::attaquer(Monstre& cible) {
    cout << nom << " lance une attaque sur " << cible.getNom() << " !" << endl;

    // Formule de dégâts imposée par le sujet : rand(0, HP_max_defenseur)
    int degats = rand() % (cible.getHpMax() + 1);

    if (degats == 0) {
        cout << "L'attaque a echoue, aucun degat inflige." << endl;
    } else {
        cout << "Coup reussi ! " << cible.getNom() << " perd " << degats << " HP." << endl;
        cible.recevoirDegats(degats);
    }

    if (!cible.estVivant()) {
        cout << cible.getNom() << " a ete vaincu de maniere fatale." << endl;
        monstresTues++;
        victoires++;
    }
}

void Joueur::agirACT(Monstre& cible, ActionAct action) {
    cout << "Action choisie : " << action.getId() << endl;
    int impact = action.executer();
    cible.modifierMercy(impact);
}

void Joueur::epargnerMercy(Monstre& cible) {
    if (cible.peutEtreEpargne()) {
        cout << "Vous avez choisi la voie pacifique : " << cible.getNom() << " est epargne." << endl;
        monstresEpargnes++;
        victoires++;
    } else {
        cout << "Le monstre est encore trop agressif pour accepter votre clemence." << endl;
    }
}

// --- GESTION DE L'INVENTAIRE ---

void Joueur::ajouterItem(Item objet) {
    inventaire.push_back(objet);
}

void Joueur::afficherInventaire() {
    if (inventaire.empty()) {
        cout << "Votre inventaire est vide." << endl;
        return;
    }

    cout << "--- INVENTAIRE DE " << nom << " ---" << endl;
    for (int i = 0; i < inventaire.size(); i++) {
        cout << i + 1 << ". " << inventaire[i].getNom()
             << " - " << inventaire[i].getValeur() << " HP"
             << " (x" << inventaire[i].getQuantite() << ")" << endl;
    }
}

void Joueur::utiliserItem(int index) {
    if (index < 0 || index >= inventaire.size()) return;

    Item& obj = inventaire[index];
    if (obj.getQuantite() > 0) {
        int soin = obj.utiliser();
        // Pour l'instant, on suppose que tous les items sont de type HEAL
        hpActuel += soin;
        if (hpActuel > hpMax) hpActuel = hpMax; // On bride aux HP max

        cout << "Vous utilisez " << obj.getNom() << " et recuperez " << soin << " HP !" << endl;
        obj.reduireQuantite();

        // Si la quantité tombe à 0, on pourrait supprimer l'item, mais on peut le laisser vide
    }
}

// --- ACCESSEURS ---

int Joueur::getVictoires() { return victoires; }
int Joueur::getMonstresTues() { return monstresTues; }
int Joueur::getMonstresEpargnes() { return monstresEpargnes; }
vector<Item>& Joueur::getInventaire() { return inventaire; }
Bestiaire& Joueur::getBestiaire() {
    return monBestiaire;
}