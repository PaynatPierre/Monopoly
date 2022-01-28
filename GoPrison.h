#ifndef CODEPROJET5_GOPRISON_H
#define CODEPROJET5_GOPRISON_H

#include "Case.h"
#include "Joueur_Pion.h"

class GoPrison : public Case{

public:
    GoPrison(Case*);
    void arreterSur(Joueur* player);
};

#endif 