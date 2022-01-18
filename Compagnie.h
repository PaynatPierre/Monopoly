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

protected:

public:
    Compagnie(const std::string&,  Case*, int, int*);
    void jouerCompagnie(Joueur* player);
    void arreterSur();
};


#endif