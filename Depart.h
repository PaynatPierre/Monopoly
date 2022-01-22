#ifndef DEPART_H
#define DEPART_H

#include <string>

#include "Case.h"
#include "Joueur_Pion.h"


class Depart: public Case {
private: 
    int prime;
public:
    Depart(int, Case*);
    void arreterSur(Joueur* player);
    void setprime(int);
    int getprime();
};




#endif