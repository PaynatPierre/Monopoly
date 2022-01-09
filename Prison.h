#ifndef PRISON_H
#define PRISON_H

class Case;
class Jeu;
class Joueur;
class Plateau;

#include "Case.h"


class Prison: public Case {
private: 

public:
    Prison(Case* ptsuivante);
    void arreterSur();
    void jouerPrison();

};


#endif