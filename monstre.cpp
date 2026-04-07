//
// Created by Amandine Baranger on 05/04/2026.
//
#include "Monstre.h"
#include "Joueur.h"
#include <iostream>
#include <random>

using namespace std;

Monstre::Monstre(string nomEntite, int hp, int atk, int def, int mGoal)
    : Entite(nomEntite, hp) {
    attaque = atk;
    defense = def;
    mercyGoal = mGoal;
    mercyActuel = 0;
}

void Monstre::attaquer(Joueur& cible) {
    cout << nom << " vous attaque !" << endl;

    int degats = rand() % (cible.getHpMax() + 1);

    if (degats == 0) {
        cout << "L'attaque de " << nom << " a echoue !" << endl;
    } else {
        cout << "Vous subissez " << degats << " points de degats." << endl;
        cible.recevoirDegats(degats);
    }
}

void Monstre::modifierMercy(int valeur) {
    mercyActuel += valeur;

    if (mercyActuel < 0) {
        mercyActuel = 0;
    } else if (mercyActuel > mercyGoal) {
        mercyActuel = mercyGoal;
    }

    cout << "La jauge Mercy de " << nom << " est maintenant a "
         << mercyActuel << "/" << mercyGoal << "." << endl;
}

bool Monstre::peutEtreEpargne() {
    return mercyActuel >= mercyGoal;
}