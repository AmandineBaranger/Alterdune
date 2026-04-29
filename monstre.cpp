//
// Created by Amandine Baranger on 05/04/2026.
//
#include "Monstre.h"
#include "Joueur.h"
#include <iostream>
#include <random>

using namespace std;

Monstre::Monstre(string nomEntite, int hp, int atk, int def, int mGoal, string a1, string a2, string a3, string a4)
    : Entite(nomEntite, hp) {
    attaque = atk;
    defense = def;
    mercyGoal = mGoal;
    mercyActuel = 0;
    actionsPossibles[0] = a1;
    actionsPossibles[1] = a2;
    actionsPossibles[2] = a3;
    actionsPossibles[3] = a4;
}

void Monstre::attaquer(Joueur& cible) {
    cout << nom << " vous attaque !" << endl;

    // Formule équilibrée : pourcentage aléatoire entre 30% et 70% des HP max
    int pourcentage = 30 + rand() % 41;  // 30 à 70
    int maxDamage = (cible.getHpMax() * pourcentage) / 100;
    int degats = rand() % (maxDamage + 1);

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

string Monstre::getAction(int index) {
    return actionsPossibles[index];
}