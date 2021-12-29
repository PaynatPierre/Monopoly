//
// Created by pierr on 29/12/2021.
//

#ifndef CODEPROJET5_PARCKGRATUIT_H
#define CODEPROJET5_PARCKGRATUIT_H
#include "Case.h"
#include <iostream>
using namespace std;


class ParckGratuit : public Case{
private:
    int cagnotte;
public:
    ParckGratuit(Case* ptsuivante, int cagnotte);
    void setcagnotte(int i);
    int getcagnotte();
    void jouerparckgratuit();
};


#endif //CODEPROJET5_PARCKGRATUIT_H
