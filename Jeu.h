#ifndef CODEPROJET4_JEU_H
#define CODEPROJET4_JEU_H

class Case;
class Jeu;
class Joueur;
class Plateau;

#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"

class Jeu {
private:
    int tourdejeu;
    int nbrdejoueur;
    Plateau plateau;
    Joueur *liste[6];
    De de1;
    De de2;
    Gobelet gobelet;

public:
    Jeu(int,int,Joueur **,De&, De&);

    int gettourdejeu();
    void settourdejeu(int);
    void toursuivant();

    int getnbrjoueur();
    void setnbrjoueur(int);

    Plateau getplateau();
    void setplateau(Plateau);

    Joueur* getjoueur(int);
    void setjoueur(Joueur*, int);

    Gobelet getgobelet();
    void setgobelet(Gobelet);

    De getde1();
    De getde2();
    void setde1(De&);
    void setde2(De&);
};


#endif
