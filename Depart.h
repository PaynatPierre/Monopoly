#ifndef DEPART_H
#define DEPART_H

#include <string>
#include "Case.h"
#include <iostream>
using namespace std;

class Depart: public Case {
private: 
    int prime;
public:
    Depart(int prime, string nom, Case* ptsuivante);
    void jouerDepart();
    void setprime(int i);
    int getprime();
};




#endif