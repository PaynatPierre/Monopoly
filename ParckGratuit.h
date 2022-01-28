#ifndef CODEPROJET5_PARCKGRATUIT_H
#define CODEPROJET5_PARCKGRATUIT_H

#include <string>
#include "Case.h"
#include "Joueur_Pion.h"

class ParckGratuit : public Case{
private:
    int cagnotte;
public:
    void arreterSur(Joueur*);
    void addcagnotte(int);
    ParckGratuit(Case*, int);
    void setcagnotte(int);
    int getcagnotte();
};

#endif