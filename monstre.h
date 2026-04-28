//
// Created by Amandine Baranger on 05/04/2026.
//

#ifndef PROJETA3S6_MONSTRE_H
#define PROJETA3S6_MONSTRE_H
#include <iostream>
#include <vector>
#include "joueur.h"
#include "entite.h"
using namespace std;
class Joueur;
class Monstre : public Entite {
protected:
    int attaque;
    int defense;
    int mercyGoal;
    int mercyActuel;
    string actionsPossibles[4]; // Tableau pour stocker les 4 actions du CSV
    vector<string> actionDisponibles;
    public:
    Monstre(string nomEntite, int hp, int atk, int def, int mGoal,string a1, string a2, string a3, string a4);
    void attaquer(Joueur& cible);
    void modifierMercy(int valeur);
    bool peutEtreEpargne();
    virtual string getCategory()=0;

    string getAction(int index);
};
#endif //PROJETA3S6_MONSTRE_H