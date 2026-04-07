//
// Created by Amandine Baranger on 07/04/2026.
//
#include "entreebestiaire.h"
#include <iostream>

using namespace std;

EntreeBestiaire::EntreeBestiaire(string nom, string cat, int hp, int atk, int def, string res) {
    nomMonstre = nom;
    categorie = cat;
    hpMax = hp;
    attaque = atk;
    defense = def;
    resultat = res;
}

void EntreeBestiaire::afficher() {
    cout << "Nom: " << nomMonstre << " | Categorie: " << categorie << endl;
    cout << "Stats -> HP: " << hpMax << ", ATK: " << attaque << ", DEF: " << defense << endl;
    cout << "Resultat du combat: " << resultat << endl;
    cout << "------------------------" << endl;
}