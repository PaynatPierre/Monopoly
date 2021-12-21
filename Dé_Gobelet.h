#ifndef Dé_h
#define Dé_h

#include <string>

class Gobelet{};

class Dé {

    friend class Gobelet;

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

class Gobelet{
    public:
    int getValeursDés(const Dé&,const Dé&);
    bool doubleValeurs(const int, const int);
};



#endif 
