#ifndef CODEPROJET4_COMPAGNIE_H
#define CODEPROJET4_COMPAGNIE_H

#include <string>
#include "Case.h"
#include "Joueur_Pion.h"
#include "Propriete.h"

class Compagnie: public Propriete{

public:
    Compagnie(const std::string&,  Case*, int, int*);
    void arreterSur(Joueur* player);
};

#endif