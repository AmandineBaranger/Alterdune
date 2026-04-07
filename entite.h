//
// Created by Amandine Baranger on 05/04/2026.
//

#ifndef PROJETA3S6_ENTITE_H
#define PROJETA3S6_ENTITE_H
#include<string>
using namespace std;

class Entite {
protected:
    string nom;
    int hpActuel;
    int hpMax;

public:
    Entite(string nom, int hp);
    string getNom();
    int getHpActuel();
    int getHpMax();
    void recevoirDegats(int degats);
    bool estVivant();
    virtual void attaquer() = 0;
};
#endif //PROJETA3S6_ENTITE_H