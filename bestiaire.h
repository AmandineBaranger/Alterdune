//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_BESTIAIRE_H
#define PROJETA3S6_BESTIAIRE_H
#include <vector>
#include "entreebestiaire.h"

using namespace std;

class Monstre; // Declaration anticipee

class Bestiaire {
private:
    vector<EntreeBestiaire> entrees;

public:
    Bestiaire();
    void ajouterEntree(Monstre& monstre, string resultat);
    void afficher();
};
#endif //PROJETA3S6_BESTIAIRE_H