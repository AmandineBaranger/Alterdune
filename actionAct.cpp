//
// Created by Amandine Baranger on 07/04/2026.
//
#include "actionact.h"

using namespace std;

ActionAct::ActionAct() {
    id = "INCONNU";
    texte = "...";
    impactMercy = 0;
}

ActionAct::ActionAct(string idAct, string texteAct, int impact) {
    id = idAct;
    texte = texteAct;
    impactMercy = impact;
}

string ActionAct::getId() {
    return id;
}

int ActionAct::executer() {
    cout << texte << endl;
    return impactMercy;
}