//
// Created by Amandine Baranger on 07/04/2026.
//
#include "boss.h"

using namespace std;

Boss::Boss(string nomEntite, int hp, int atk, int def, int mGoal, string a1, string a2, string a3, string a4)
    : Monstre(nomEntite, hp, atk, def, mGoal, a1, a2, a3, a4) {
}

string Boss::getCategory() {
    return "BOSS";
}