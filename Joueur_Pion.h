#ifndef Joueur_Pion_h
#define Joueur_Pion_h

#include <string>
#include "Propriété.h"
#include "Case.h"

class Pion;

class Joueur{
    
    private:

    bool status;
    std::string Nom;
    int solde;
    Pion pion;
    Propriété* *liste_acquisitions; // tableau dynamique de pointeurs, pointant sur les propriétés du joueur
    
    public:

    Joueur(const bool, const std::string &, const int, const Pion&, const Propriété**);

    bool getStatus();
    std::string getNom();
    int getSolde();
    Pion getPion();
    Propriété** getListe_acquisitions();

    void setStatus(const bool);
    void setNom(const std::string&);
    void setSolde(int);
    void setPion(const Pion &);
    void setListe_acquisitions(const Propriété**);

    void crediter(int);
    void debbiter(int);
    void jouer(Joueur*);
    void perdre();
    
};

class Pion{

    friend class Joueur;

    private :

    Joueur* ptJoueur;
    Case* ptCase;

    public:

    Pion(const Joueur* ,const Case*); 
    Joueur* getPtJoueur();
    Case* getPtCase();

    void setPtJoueur(const Joueur*);
    void setPtCase(const Case*);

    void deplacer();

};

#endif