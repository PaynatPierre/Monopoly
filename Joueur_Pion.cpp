#include "Joueur_Pion.h"
#include "Propriété.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Joueur :: Joueur(const bool Status = true, const std::string & Nom, const Pion& P,Propriete** Liste_de_proprietes = NULL, int NbPropriete = 0, int NbDouble = 0, int Solde = 0){
    status =  Status;
    nom = Nom;
    solde = Solde;
    nbPropriete = NbPropriete;
    pion = new Pion(P);
    if (nbPropriete != 0){
        const int init = 2*nbPropriete;
        liste_acquisitions =  new Propriete*[init];
        for (int i=0; i<nbPropriete;i++)
            liste_acquisitions[i] = Liste_de_proprietes[i];
    }
    else{
        liste_acquisitions =  new Propriete*[10];
    }
    nbDouble = NbDouble;

}


bool Joueur :: getStatus(){
    return status;
}

std::string Joueur :: getNom(){
    return nom;
}

int Joueur :: getSolde(){
    return solde;
}

Pion* Joueur :: getPion(){
    return pion;
    
}

int Joueur :: getNbPropriete(){
    return nbPropriete;
}

Propriete** Joueur :: getListe_acquisitions(){
    return liste_acquisitions;
}

int Joueur :: getNbDouble(){
    return nbDouble;
}

void Joueur :: setStatus(const bool Status){
    status = Status;
}

void Joueur :: setNom(const std::string& Nom){
    nom = Nom;
}

void Joueur :: setSolde(int Solde){
    solde = Solde;    
}

void Joueur :: setNbPropriete(int NbPropriete){
    nbPropriete = NbPropriete;
}

void Joueur :: setPion(const Pion& P){
    delete pion;
    pion = new Pion(P);

} 

void Joueur :: setNbDouble(int NbDouble){
    nbDouble = NbDouble;
}

void Joueur :: ajouterAcquisition(Propriete* Prop){
    if (liste_acquisitions[nbPropriete-1] == NULL){
        liste_acquisitions[nbPropriete] = Prop;
        nbPropriete +=1;
    }
    else{
        const int ancienNb = nbPropriete;
        Propriete* tab_cop[ancienNb];
        for (int i=0; i < ancienNb; i++)
            tab_cop[i]= liste_acquisitions[i];
        delete liste_acquisitions;
        liste_acquisitions = new Propriete* [ancienNb * 2];
        for (int i=0; i < ancienNb; i++)
            liste_acquisitions[i]= tab_cop[i];
        liste_acquisitions[nbPropriete] = Prop;
        nbPropriete +=1;        
    }
}

void Joueur :: crediter(int credit){
    solde += credit;
}

void Joueur :: debiter(int debit){
    solde -= debit;
}

void Joueur :: jouer(Joueur*){
    // a coder
}


void Joueur :: perdre(){
    status =  false;
    solde = 0;
    delete pion;
    delete liste_acquisitions;
}



Pion :: Pion(Joueur* ptJ,Case* ptC){
    ptJoueur = ptJ;
    ptCase = ptC;
} 

Pion :: Pion(const Pion&P ){
    ptJoueur = P.ptJoueur;
    ptCase = P.ptCase;
}

Joueur* Pion :: getPtJoueur(){
    return ptJoueur;
}

Case* Pion :: getPtCase(){
    return ptCase;
}

void Pion :: setPtJoueur(Joueur* ptJ){
    ptJoueur = ptJ;
}

void Pion :: setPtCase(Case* ptC){
    ptCase = ptC;
}

void Pion :: deplacer(){
    // a coder
}