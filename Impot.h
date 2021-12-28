//
// Created by pierr on 28/12/2021.
//

#ifndef CODEPROJET5_IMPOT_H
#define CODEPROJET5_IMPOT_H
#include "Case.h"
#include <iostream>
using namespace std;

class Impot : public Case{
private:
    int taxe;
public:
    Impot(string nom, Case* ptsuivante, int taxe);
    void settaxe(int i);
    int gettaxe();
    void jouerimpot()

};


#endif //CODEPROJET5_IMPOT_H
