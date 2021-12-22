#ifndef Joueur_Pion_h
#define Joueur_Pion_h

#include <string>
#include "Propriété.h"
#include "Case.h"


class Joueur;


class Pion{

    private :

    Joueur* ptJoueur;
    Case* ptCase;

    public:

    Pion(Joueur* ,Case*); 
    Pion(const Pion&);

    Joueur* getPtJoueur();
    Case* getPtCase();

    void setPtJoueur(Joueur*);
    void setPtCase(Case*);

    void deplacer();

};

class Joueur{

    friend class Pion;
    private:

    bool status;
    std::string nom;
    int solde;
    Pion *pion; //allocation dynalique de l'objet Pion
    int nbPropriété;
    Propriété* *liste_acquisitions; // tableau dynamique de pointeurs, pointant sur les propriétés du joueur
    
    public:

    Joueur(const bool, const std::string &, const int, const Pion&,const int, const Propriété**);

    bool getStatus();
    std::string getNom();
    int getSolde();
    Pion* getPion();
    int getNbPropriete();
    Propriété** getListe_acquisitions();

    void setStatus(const bool);
    void setNom(const std::string&);
    void setSolde(int);
    void setNbPropriete(int);
    void setPion(const Pion&);

    void ajouterAcquisition(Propriété*);
    void crediter(int);
    void debiter(int);
    void jouer(Joueur*);
    void perdre();
    
};

#endif