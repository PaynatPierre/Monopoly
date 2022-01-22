#ifndef CODEPROJET5_IMPOT_H
#define CODEPROJET5_IMPOT_H

#include <string>
#include "Case.h"
#include "Joueur_Pion.h"


class Impot : public Case{
private:
    int taxe;
public:
    
    Impot(std::string, Case*, int);
    void settaxe(int);
    int gettaxe();
    void arreterSur(Joueur*);

};


#endif
