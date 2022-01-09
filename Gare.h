//
// Created by pierr on 09/01/2022.
//

#ifndef CODEPROJET5_GARE_H
#define CODEPROJET5_GARE_H
#include "propriete.h"
#include "Case.h"


class Gare : public propriete{
private:
public:
    Gare(string, Case*, int, int *loyer);
    void jouergare();
    void arriverSur();
};


#endif //CODEPROJET5_GARE_H
