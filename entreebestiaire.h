//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_ENTREEBESTIAIRE_H
#define PROJETA3S6_ENTREEBESTIAIRE_H
#include <string>

using namespace std;

class EntreeBestiaire {
private:
    string nomMonstre;
    string categorie;
    int hpMax;
    int attaque;
    int defense;
    string resultat;

public:
    EntreeBestiaire(string nom, string cat, int hp, int atk, int def, string res);
    void afficher();
};
#endif //PROJETA3S6_ENTREEBESTIAIRE_H