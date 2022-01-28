#ifndef CHANCE_H
#define CHANCE_H

#include <string>
#include "Case.h"
#include "Joueur_Pion.h"

class Chance: public Case {
private: 
    std::string m_carteChance[16];
public:
    void arreterSur(Joueur* player);
    Chance(std::string, Case*);
    std::string getCarteChance(int);
    void setCarteChance(int, std::string);

};

#endif