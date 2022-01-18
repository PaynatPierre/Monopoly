#ifndef COMMUNAUTE_H
#define COMMUNAUTE_H

class Case;
class Jeu;
class Joueur;
class Plateau;


#include <string>
#include "Case.h"

class Communaute: public Case {
private: 
	std::string m_carteCommunaute[16];
public:
    void arreterSur(Joueur* player);
    Communaute(std::string, Case*);
    std::string getCarteCommunaute(int);
    void setCarteCommunaute(int, std::string);

};





#endif