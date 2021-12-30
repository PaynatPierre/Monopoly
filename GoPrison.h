#ifndef CODEPROJET5_GOPRISON_H
#define CODEPROJET5_GOPRISON_H

class Case;
class Jeu;
class Joueur;
class Plateau;


#include "Case.h"

class GoPrison : public Case{
public:
    GoPrison(Case*);
    void setptsuivante(Case*);
    Case* getptsuivante();
    void jouergoprison();
private:
    Case* ptsuivante;
};


#endif 
