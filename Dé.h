#ifndef Dé_h
#define Dé_h

#include <string>

class Dé {

    private:

    int nbFaces;
    int *valeurs; /* tableau dynamique */

    public:
    Dé();
    Dé(const int, const int*);
    void setNbFaces(const int);
    void setValeurs(const int*);
    int getNbFaces();
    int* setValeurs();

};


#endif 
