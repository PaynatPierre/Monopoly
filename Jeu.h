//
// Created by pierr on 15/12/2021.
//

#ifndef CODEPROJET4_JEU_H
#define CODEPROJET4_JEU_H

#include "Plateau.h"

class Jeu {
private:
    int tourdejeu;
    static int nbrdejoueur;
    Plateau plateau;
    Joueur *liste[nbrdejoueur];
    De des[2];
    Goblet goblet;
protected:
public:
    Jeu(int nbrplayer, Joeur **players);

    int gettourdejeu();
    void settourdejeu(int i);
    void toursuivant();

    int getnbrjoueur();
    void setnbrjoueur(int i);

    Plateau getplateau();
    void setplateau(Plateau pl);

    Joueur* getjoueur(int i);
    void setjoueur(Joueur* j, int i);

    Goblet getgoblet();
    void setgoblet(Goblet g);

    De getde(int i);
    void setde(De d,int i);
};


#endif //CODEPROJET4_JEU_H
