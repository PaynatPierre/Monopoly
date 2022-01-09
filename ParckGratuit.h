#ifndef CODEPROJET5_PARCKGRATUIT_H
#define CODEPROJET5_PARCKGRATUIT_H

class Case;
class Jeu;
class Joueur;
class Plateau;



#include "Case.h"
#include <string>


class ParckGratuit : public Case{
private:
    int cagnotte;
public:
    void arreterSur();
    ParckGratuit(Case*, int);
    void setcagnotte(int);
    int getcagnotte();
    void jouerparckgratuit();
};


#endif
