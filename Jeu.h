#ifndef CODEPROJET4_JEU_H
#define CODEPROJET4_JEU_H


#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"

class Jeu {
private:
    int nbrdejoueur;
    int tourdejeu;
    int joueurcourant;
    int nbelimine;
    Plateau plateau;
    Joueur liste[6];
    De de1;
    De de2;

public:

    Jeu(Plateau&, int);

    void create_joueur(std::string &, std::string &);
    void schedule();
    void jouer();
    int gettourdejeu();
    void settourdejeu(int);
    void toursuivant();

    int getnbrjoueur();
    void setnbrjoueur(int);

    Plateau getplateau();
    void setplateau(Plateau);

    Joueur getjoueur(int);
    void setjoueur(Joueur, int);

    De getde1();
    De getde2();
};


#endif
