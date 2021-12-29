#ifndef PRISON_H
#define PRISON_H

#include <string>
#include "Case.h"
using namespace std;


class Prison: public Case {
private: 

public:
    Prison(Case* ptsuivante)
    void jouerPrison();

};


#endif