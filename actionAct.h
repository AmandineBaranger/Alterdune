//
// Created by Amandine Baranger on 07/04/2026.
//

#ifndef PROJETA3S6_ACTIONACT_H
#define PROJETA3S6_ACTIONACT_H
#include <string>
#include <iostream>

using namespace std;

class ActionAct {
private:
    string id;
    string texte;
    int impactMercy;

public:
    ActionAct();
    ActionAct(string idAct, string texteAct, int impact);

    string getId();
    int executer();
};
#endif //PROJETA3S6_ACTIONACT_H