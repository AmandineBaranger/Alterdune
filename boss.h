//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_BOSS_H
#define PROJETA3S6_BOSS_H
#include "monstre.h"
#include <string>

using namespace std;

class Boss : public Monstre {
public:
    Boss(string nomEntite, int hp, int atk, int def, int mGoal, string a1, string a2, string a3, string a4);
    string getCategory() override;
};
#endif //PROJETA3S6_BOSS_H