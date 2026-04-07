//
// Created by Amandine Baranger on 05/04/2026.
//

#ifndef PROJETA3S6_JOUEUR_H
#define PROJETA3S6_JOUEUR_H
#include <iostream>
#include <string>

#include "entite.h"
#include "monstre.h"
#include "actionAct.h"
using namespace std;


class Monstre;

class Joueur : public Entite {
protected:
    int monstresTues;
    int monstresEpargnes;
    int victoires;

public:
    Joueur(string nomEntite, int hp);
    void attaquer(Monstre& cible);
    void agirACT(Monstre& cible, ActionAct action);
    void epargnerMercy(Monstre& cible);
    int getVictoires();
};
#endif //PROJETA3S6_JOUEUR_H