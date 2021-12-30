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
    De des[2]; /*A modifier les des sont pas de cette forme*/
    Gobelet goblet;
protected:
public:
    Jeu(int,Joueur **);

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

    De getde(int i);
    void setde(De d,int i);
};


#endif
