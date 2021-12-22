#include "Joueur_Pion.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Joueur :: Joueur(const bool Status = true, const std::string & Nom, const int Solde = 0, const Pion& P, const int NbPropriete = 0, const Propriété** Liste_de_proprietes){
    status =  Status;
    nom = Nom;
    solde = Solde;
    pion = new Pion(P);
    liste_acquisitions =  new Propriété*[10];

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
    return nbPropriété;
}

Propriété** Joueur :: getListe_acquisitions(){
    return liste_acquisitions;
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

void Joueur :: setPion(const Pion& P){
    delete pion;
    pion = new Pion(P);

} 

void Joueur :: setNbPropriete(int NbPropriete){
    nbPropriété = NbPropriete;
}

void Joueur :: ajouterAcquisition(Propriété* Propriete){
    if (liste_acquisitions[nbPropriété-1] == NULL){
        liste_acquisitions[nbPropriété] = Propriete;
        nbPropriété +=1;
    }
    else{
        const int ancienNb = nbPropriété;
        Propriété* tab_cop[ancienNb];
        for (int i=0; i < ancienNb; i++)
            tab_cop[i]= liste_acquisitions[i];
        delete liste_acquisitions;
        liste_acquisitions = new Propriété*[ancienNb * 2];
        for (int i=0; i < ancienNb; i++)
            liste_acquisitions[i]= tab_cop[i];
        liste_acquisitions[nbPropriété] = Propriete;
        nbPropriété +=1;        
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