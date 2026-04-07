//
// Created by Amandine Baranger on 07/04/2026.
//
#include "monstrenormal.h"

using namespace std;

MonstreNormal::MonstreNormal(string nomEntite, int hp, int atk, int def, int mGoal)
    : Monstre(nomEntite, hp, atk, def, mGoal) {
}

string MonstreNormal::getCategory() {
    return "NORMAL";
}