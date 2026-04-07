//
// Created by Amandine Baranger on 06/04/2026.
//
#include "jeu.h"

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
void Jeu::chargerFichiers() {
    cout << "Chargement des donnees en cours..." << endl;
}

void Jeu::demarrer() {
    cout << "=== BIENVENUE DANS ALTERDUNE ===" << endl;
    chargerFichiers();
}

void Jeu::boucleCombat(Joueur& j, Monstre* m) {
    cout << "Un combat commence contre " << m->getNom() << " !" << endl;
}

void Jeu::verifierFinDePartie(Joueur& j) {
    if (j.getVictoires() >= 10) {
        cout << "Fin de la partie atteinte !" << endl;
    }
}