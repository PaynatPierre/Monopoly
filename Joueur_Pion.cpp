#include "Joueur_Pion.h"
#include "De_Gobelet.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Joueur::Joueur(){

}

Joueur :: Joueur ( string &Nom, string& nom_Pion, Case * ptCase, Propriete** Liste_de_proprietes = NULL, int NbPropriete = 0, int NbCompagnie = 0, int NbDouble = 0, int Solde = 0, int nombregare = 0, bool enprison = false, int tourenprison=0,bool Status = true ) : pion(nom_Pion,ptCase) {
    nom = Nom;
    nbgare = nombregare;
    inprison = enprison;
    tourinprison = tourenprison;
    status =  Status;
    solde = Solde;
    nbPropriete = NbPropriete;
    nbCompagnie = NbCompagnie;
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
    return &pion;
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

    for(int i=0;i<nbPropriete;i++){
        liste_acquisitions[i]->setProprietaire(NULL);
    }

    delete liste_acquisitions;
}



Pion :: Pion(string &Nom,Case* ptC){
    nom = Nom;
    ptCase = ptC;
} 

string Pion::getNom(){
    return nom;
}

Pion :: Pion(const Pion&P ){
    ptCase = P.ptCase;
}

Case* Pion :: getPtCase(){
    return ptCase;
}

void Pion :: setPtCase(Case* ptC){
    ptCase = ptC;
}

void Pion :: setNom(string& Nom){
    nom = Nom;
}

void Pion :: deplacer(){
    setPtCase(ptCase->getSuivante());
}

Pion::Pion(){

}