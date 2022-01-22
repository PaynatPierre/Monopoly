#include "Plateau.h"

#include <string>
#include <iostream>

using namespace std;

Plateau:: Plateau() {
    for (int i=0; i<40; i++)
        cases[i] = NULL;
}

Plateau :: Plateau(Plateau& p){
    for (int i=0; i<40; i++)
        cases[i] = (p.cases)[i];
}

Case* Plateau::getcase(int i) {
    return cases[i];
}

void Plateau :: arreterSur(int i,Joueur *J){
    cases[i]->arreterSur(J);
}

void Plateau::setcase(Case* c, int i) {
    cases[i] = c;
}

