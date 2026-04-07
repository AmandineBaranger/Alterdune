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
    vector<string> actionDisponibles;
    public:
    Monstre(string nomEntite, int hp, int atk, int def, int mGoal);
    void attaquer(Joueur& cible);
    void modifierMercy(int valeur);
    bool peutEtreEpargne();
    virtual string getCategory()=0;
};
#endif //PROJETA3S6_MONSTRE_H