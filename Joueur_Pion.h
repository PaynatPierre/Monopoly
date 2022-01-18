#ifndef Joueur_Pion_h
#define Joueur_Pion_h

#include "De_gobelet.h"
#include <string>


class Case;
class Jeu;
class Joueur;
class Plateau;
class Pion;
class Propriete;


class Joueur{

    friend class Pion;
    private:

        bool status;
        std::string nom;
        int solde;
        Pion *pion; //allocation dynamique de l'objet Pion
        int nbPropriete;
        int nbCompagnie;
        Propriete* *liste_acquisitions; // tableau dynamique de pointeurs, pointant sur les proprietes du joueur
        int nbDouble;
        int nbgare;
        bool inprison;
        int tourinprison;
        int valeurde;

    public:

        Joueur(const std::string &, Pion&, const bool, Propriete**,int,int,int,int,int,bool,int);
    
        int getvaleurde();
        bool getStatus();
        std::string getNom();
        int getSolde();
        Pion* getPion();
        int getNbPropriete();
        int getNbCompagnie();
        Propriete** getListe_acquisitions();
        int getNbDouble();
        int getnbgare();
        bool getinprison();
        int gettourinprison();

        void setvaleurde(int);
        void addgare();
        void setinprison(bool);
        void settourinprison(int);
        void setStatus(const bool);
        void setNom(const std::string&);
        void setSolde(int);
        void setNbPropriete(int);
        void addCompagnie();
        void setPion(const Pion&);
        void setNbDouble(int);

        void ajouterAcquisition(Propriete*);
        void crediter(int);
        void debiter(int);
        void jouer();
        void perdre();
    
};

class Pion{

    private :

        std::string nom;
        Joueur* ptJoueur;
        Case* ptCase;

    public:

        Pion(std::string&, Joueur* ,Case*); 
        Pion(const Pion&);

        std::string getNom();
        Joueur* getPtJoueur();
        Case* getPtCase();

        void  setNom(std::string&);
        void setPtJoueur(Joueur*);
        void setPtCase(Case*);

        void deplacer();

};

#endif