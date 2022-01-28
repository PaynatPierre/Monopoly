#ifndef CODEPROJET5_GARE_H
#define CODEPROJET5_GARE_H

#include <string>
#include "Case.h"
#include "Propriete.h"
#include "Joueur_Pion.h"



class Gare : public Propriete{
public:
    Gare(std::string, Case*, int, int *);
    virtual void arreterSur(Joueur*);
};


#endif