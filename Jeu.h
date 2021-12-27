//
// Created by pierr on 15/12/2021.
//

#ifndef CODEPROJET4_JEU_H
#define CODEPROJET4_JEU_H

#include "Plateau.h"
#include "Joueur_Pion.h"
#include "Dé_Gobelet.h"

class Jeu {
private:
    int tourdejeu;
    static int nbrdejoueur;
    Plateau plateau;
    Joueur *liste[nbrdejoueur];
    Dé des[2]; /*A modifier les des sont pas de cette forme*/
    Gobelet goblet;
protected:
public:
    Jeu(int nbrplayer, Joueur **players);

    int gettourdejeu();
    void settourdejeu(int i);
    void toursuivant();

    int getnbrjoueur();
    void setnbrjoueur(int i);

    Plateau getplateau();
    void setplateau(Plateau pl);

    Joueur* getjoueur(int i);
    void setjoueur(Joueur* j, int i);

    Gobelet getgobelet();
    void setgobelet(Gobelet g);

    Dé getde(int i);
    void setde(Dé d,int i);
};


#endif CODEPROJET4_JEU_H
