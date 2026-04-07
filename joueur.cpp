//
// Created by Amandine Baranger on 05/04/2026.
//
#include "Joueur.h"
#include "Monstre.h"
#include "ActionAct.h"
#include <iostream>
#include <random>

using namespace std;

Joueur::Joueur(string nomEntite, int hp) : Entite(nomEntite, hp) {
    monstresTues = 0;
    monstresEpargnes = 0;
    victoires = 0;
}

void Joueur::attaquer(Monstre& cible) {
    cout << nom << " attaque " << cible.getNom() << " !" << endl;

    int degats = rand() % (cible.getHpMax() + 1);

    if (degats == 0) {
        cout << "Coup rate ! " << cible.getNom() << " ne subit aucun degat." << endl;
    } else {
        cout << cible.getNom() << " subit " << degats << " points de degats." << endl;
        cible.recevoirDegats(degats);
    }

    if (!cible.estVivant()) {
        cout << "Vous avez vaincu " << cible.getNom() << " !" << endl;
        monstresTues++;
        victoires++;
    }
}

void Joueur::agirACT(Monstre& cible, ActionAct action) {
    cout << "Vous utilisez l'action : " << action.getId() << endl;
    int impact = action.executer();
    cible.modifierMercy(impact);
}

void Joueur::epargnerMercy(Monstre& cible) {
    if (cible.peutEtreEpargne()) {
        cout << "Vous avez epargne " << cible.getNom() << " !" << endl;
        monstresEpargnes++;
        victoires++;
    } else {
        cout << cible.getNom() << " n'est pas encore pret a etre epargne..." << endl;
    }
}

int Joueur::getVictoires(){
    return victoires;
}