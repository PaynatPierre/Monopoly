#ifndef Joueur_Pion_h
#define Joueur_Pion_h


#include <string>
#include "Case.h"
#include "Propriete.h"

class Joueur;
class Pion{
    friend class Joueur;
    private :

        std::string nom;
        Case* ptCase;

    public:

        Pion(std::string&,Case*); 
        Pion(const Pion&);
        Pion();

        std::string getNom();
        Case* getPtCase();

        void  setNom(std::string&);
        void setPtCase(Case*);
        void operator++(int);

};

class Joueur{

    private:

        bool status;
        std::string nom;
        int solde;
        Pion pion;
        int nbPropriete;
        int nbCompagnie;
        Propriete* *liste_acquisitions; // tableau dynamique de pointeurs, pointant sur les proprietes du joueur
        int nbDouble;
        int nbgare;
        bool inprison;
        int tourinprison;
        int valeurde;

    public:

        Joueur();
        Joueur(std::string &, std::string &, Case*,Propriete**, int,int,int,int,int,bool,int,bool);
    
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

        void operator+=(Propriete*);
        void operator+=(int);
        void operator-=(int);

        void displayInfo();
        void perdre();
    
};

#endif