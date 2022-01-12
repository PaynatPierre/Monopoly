#ifndef CHANCE_H
#define CHANCE_H

class Case;
class Jeu;
class Joueur;
class Plateau;

#include <string>
#include "Case.h"

class Chance: public Case {
private: 
    std::string m_carteChance[16];
public:
    void arreterSur();
    Chance(std::string, Case*);
    void jouerChance();
    std::string getCarteChance(int);
    void setCarteChance(int, std::string);

};




#endif