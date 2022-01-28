#ifndef PRISON_H
#define PRISON_H

#include "Case.h"
#include "Joueur_Pion.h"

class Prison: public Case {
private: 

public:
    Prison(Case* ptsuivante);
    void arreterSurPrison(Joueur*, int, int);
    void arreterSur(Joueur*);

};

#endif