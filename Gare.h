//
// Created by pierr on 09/01/2022.
//

#ifndef CODEPROJET5_GARE_H
#define CODEPROJET5_GARE_H
#include "propriete.h"
#include "Case.h"
#include <string>


class Gare : public Propriete{
private:
public:
    Gare(std::string, Case*, int, int *loyer);
    void arreterSur(Joueur* player);
};


#endif //CODEPROJET5_GARE_H
