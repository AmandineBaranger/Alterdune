//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_ITEM_H
#define PROJETA3S6_ITEM_H
#include <string>

using namespace std;

class Item {
private:
    string nom;
    string type;
    int valeur;
    int quantite;

public:
    Item();
    Item(string n, string t, int v, int q);

    string getNom();
    int getQuantite();
    int getValeur();

    int utiliser();
    void reduireQuantite();
};
#endif //PROJETA3S6_ITEM_H