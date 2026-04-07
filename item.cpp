//
// Created by Amandine Baranger on 07/04/2026.
//
#include "item.h"

using namespace std;

Item::Item() {
    nom = "";
    type = "";
    valeur = 0;
    quantite = 0;
}

Item::Item(string n, string t, int v, int q) {
    nom = n;
    type = t;
    valeur = v;
    quantite = q;
}

string Item::getNom() {
    return nom;
}

int Item::getQuantite() {
    return quantite;
}

int Item::utiliser() {
    if (quantite > 0) {
        return valeur;
    }
    return 0;
}

void Item::reduireQuantite() {
    if (quantite > 0) {
        quantite--;
    }
}