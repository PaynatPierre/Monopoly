#ifndef De_h
#define De_h

class Case;
class Jeu;
class Joueur;
class Plateau;

#include "Joueur_Pion.h"


class De {

    private:

    int nbFaces;
    int *valeurs; /* tableau dynamique */
    int valeur_actuelle;

    public:
    De();
    De(int, int*);
    De(const De&);
    void setNbFaces(int);
    void setValeurs(int*);
    void setValeur(int);
    int getNbFaces();
    int getValeur();
    int* getValeurs();
    void lancerDe();
    

};



/*
class Gobelet{
    public:
    Gobelet();
    int getValeursDes(Joueur &,const De&,const De&);
    bool doubleValeurs(const int, const int);
};

*/

#endif 
