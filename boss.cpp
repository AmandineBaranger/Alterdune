//
// Created by Amandine Baranger on 07/04/2026.
//
#include "boss.h"

using namespace std;

Boss::Boss(string nomEntite, int hp, int atk, int def, int mGoal)
    : Monstre(nomEntite, hp, atk, def, mGoal) {
}

string Boss::getCategory() {
    return "BOSS";
}