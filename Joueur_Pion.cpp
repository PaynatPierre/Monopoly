#include "Joueur_Pion.h"
#include "Propriete.h"
#include "Case.h"
#include "De_gobelet.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Joueur :: Joueur(const std::string &Nom, Pion& P, const bool Status = true,Propriete** Liste_de_proprietes = NULL, int NbPropriete = 0, int NbCompagnie = 0, int NbDouble = 0, int Solde = 0, int nombregare = 0, bool enprison = false, int tourenprison=0){
    nbgare = nombregare;
    inprison = enprison;
    tourinprison = tourenprison;
    status =  Status;
    nom = Nom;
    solde = Solde;
    nbPropriete = NbPropriete;
    nbCompagnie = NbCompagnie;
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
    valeurde = 0;

}

int Joueur :: gettourinprison(){
    return tourinprison;
}

bool Joueur :: getinprison(){
    return inprison;
}

int Joueur :: getnbgare(){
    return nbgare;
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

int Joueur :: getNbCompagnie(){
    return nbCompagnie;
}

Propriete** Joueur :: getListe_acquisitions(){
    return liste_acquisitions;
}

int Joueur :: getNbDouble(){
    return nbDouble;
}

void Joueur :: setinprison(bool b){
    inprison = b;
}

void Joueur::addgare(){
    nbgare += 1;
}

void Joueur::settourinprison(int i){
    tourinprison = i;
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

void Joueur :: addCompagnie(){
    nbCompagnie += 1;
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
        delete[] liste_acquisitions;
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

void Joueur :: perdre(){
    status =  false;
    solde = 0;
    delete pion;

    for(int i=0;i<this->nbPropriete;i++){
        this->liste_acquisitions[i]->setProprietaire(NULL);
    }

    delete liste_acquisitions;
}


string Pion::getNom(){
    return nom;
}

Pion :: Pion(string &Nom, Joueur* ptJ,Case* ptC){
    nom = Nom;
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

void Pion :: setNom(string& Nom){
    nom = Nom;
}

void Pion :: deplacer(){
    this->setPtCase(this->ptCase->getSuivante());
}