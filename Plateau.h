#ifndef CODEPROJET4_PLATEAU_H
#define CODEPROJET4_PLATEAU_H

class Case;
class Jeu;
class Joueur;
class Plateau;


#include "Case.h"


class Plateau {
private:
    Case* cases[40];
public:
    Plateau();
    Case* getcase(int);
    void setcase(Case*, int);
    void creercase();
};


#endif 
