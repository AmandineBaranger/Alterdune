//
// Created by Amandine Baranger on 07/04/2026.
//
#include "miniboss.h"

using namespace std;

Miniboss::Miniboss(string nomEntite, int hp, int atk, int def, int mGoal)
    : Monstre(nomEntite, hp, atk, def, mGoal) {
}

string Miniboss::getCategory() {
    return "MINIBOSS";
}