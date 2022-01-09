#ifndef CODEPROJET4_COMPAGNIE_H
#define CODEPROJET4_COMPAGNIE_H


class Case;
class Jeu;
class Joueur;
class Plateau;


#include <string>
#include "Case.h"
#include "Propriete.h"

class Compagnie: public Propriete{

private:
    int nbcompagnies;
protected:

public:
    Compagnie(const std::string&,  Case*,int, int, int*);
    void jouerCompagnie();
    int getnb_compagnie();
    void setnb_compagnie(int);
    void arreterSur();
};


#endif