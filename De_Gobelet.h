#ifndef De_h
#define De_h

class Case;
class Jeu;
class Joueur;
class Plateau;

#include "Joueur_Pion.h"


class De {

    friend class Gobelet;

    private:

    int nbFaces;
    int *valeurs; /* tableau dynamique */

    public:
    De();
    De(const int, const int*);
    void setNbFaces(const int);
    void setValeurs(const int*);
    int getNbFaces();
    int* setValeurs();

};

class Gobelet{
    public:
    int getValeursDes(Joueur &,const De&,const De&);
    bool doubleValeurs(const int, const int);
};



#endif 
