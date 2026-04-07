//
// Created by Amandine Baranger on 05/04/2026.
//
#include "entite.h"

Entite::Entite(string nomEntite, int hp) {
    nom = nomEntite;
    hpMax = hp;
    hpActuel = hp;
}

string Entite::getNom() {
    return nom;
}

int Entite::getHpActuel() {
    return hpActuel;
}
int Entite::getHpMax() {
    return hpMax;
}

void Entite::recevoirDegats(int degats) {
    hpActuel -= degats;
    if (hpActuel < 0) {
        hpActuel = 0;
    }
}

bool Entite::estVivant() {
    if (hpActuel <= 0) {
        return false;
    }
    return true;
}
