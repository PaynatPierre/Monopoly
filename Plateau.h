#ifndef CODEPROJET4_PLATEAU_H
#define CODEPROJET4_PLATEAU_H

#include "Case.h"

class Plateau {
private:
    Case* cases[40];
public:
    Plateau();
    Plateau(Plateau&p);
    Case* getcase(int);
    void arreterSur(int i, Joueur*);
    void setcase(Case*, int);
};

#endif