#ifndef CODEPROJET5_IMPOT_H
#define CODEPROJET5_IMPOT_H

class Case;
class Jeu;
class Joueur;
class Plateau;


#include "Case.h"
#include <string>


class Impot : public Case{
private:
    int taxe;
public:
    void arreterSur(Joueur*);
    Impot(std::string, Case*, int);
    void settaxe(int);
    int gettaxe();

};


#endif
