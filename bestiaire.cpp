//
// Created by Amandine Baranger on 07/04/2026.
//
#include "bestiaire.h"
#include "monstre.h" // On a besoin des infos du monstre ici
#include <iostream>

using namespace std;

Bestiaire::Bestiaire() {
    // Le vecteur se cree vide automatiquement
}

void Bestiaire::ajouterEntree(Monstre& monstre, string resultat) {
    // On extrait les infos du monstre pour creer une nouvelle entree
    EntreeBestiaire nouvelleEntree(
        monstre.getNom(),
        monstre.getCategory(),
        monstre.getHpMax(),
        0, // atk et def non definis dans les getteurs de base pour le moment
        0,
        resultat
    );

    entrees.push_back(nouvelleEntree);
}

void Bestiaire::afficher() {
    cout << "=== BESTIAIRE ===" << endl;

    if (entrees.empty()) {
        cout << "Le bestiaire est vide." << endl;
    } else {
        for (EntreeBestiaire& e : entrees) {
            e.afficher();
        }
    }
}