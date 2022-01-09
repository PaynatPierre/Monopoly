#ifndef DEPART_H
#define DEPART_H

class Case;
class Jeu;
class Joueur;
class Plateau;

#include <string>
#include "Case.h"


class Depart: public Case {
private: 
    int prime;
public:
    Depart(int, Case*);
    void arreterSur();
    void jouerDepart();
    void setprime(int);
    int getprime();
};




#endif