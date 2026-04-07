//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_MONSTRENORMAL_H
#define PROJETA3S6_MONSTRENORMAL_H
#include "monstre.h"
#include <string>

using namespace std;

class MonstreNormal : public Monstre {
public:
    MonstreNormal(string nomEntite, int hp, int atk, int def, int mGoal);
    string getCategory() override;
};
#endif //PROJETA3S6_MONSTRENORMAL_H