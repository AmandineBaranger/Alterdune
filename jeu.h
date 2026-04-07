//
// Created by Amandine Baranger on 06/04/2026.
//

#ifndef PROJETA3S6_JEU_H
#define PROJETA3S6_JEU_H
#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "joueur.h"
#include "monstre.h"
#include "actionact.h"

using namespace std;

class Jeu {
private:
    map<string, ActionAct> catalogueActions;
    vector<Monstre*> baseMonstres;

public:
    Jeu();
    ~Jeu();
    void demarrer();
    void chargerFichiers();
    void boucleCombat(Joueur& j, Monstre* m);
    void verifierFinDePartie(Joueur& j);
};
#endif //PROJETA3S6_JEU_H