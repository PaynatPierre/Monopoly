//
// Created by pierr on 15/12/2021.
//

#include "Jeu.h"
#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"
#include <iostream>
using namespace std;


Jeu :: Jeu ( Joueur ** liste_de_joueurs, int t = 0, int bonjour = 8) : de1(), de2(), plateau(){
    nbrdejoueur = bonjour;
    nbelimine = 0;
    tourdejeu = t;
    joueurcourant=0;
    plateau.creercase();
    for (int i=0; i<nbrdejoueur ; i++){
        liste[i] = liste_de_joueurs[i];
        liste[i]->getPion()->setPtCase(plateau.getcase(0));
    }   
     
}
//TODO geter et setter de nbelimine

void Jeu::jouer(){
    if(this->liste[this->joueurcourant]->getStatus()){
        de1.lancerDe();
        de2.lancerDe();

    }else{
        if(this->joueurcourant == nbrdejoueur - 1){
            joueurcourant = 0;
        }else{
            joueurcourant += 1;
        }

    }
}

int Jeu::gettourdejeu(){
    return tourdejeu;
}
void Jeu::settourdejeu(int i){
    tourdejeu = i;
}
void Jeu::toursuivant(){
    tourdejeu = tourdejeu +1;
}

int Jeu::getnbrjoueur(){
    return this->nbrdejoueur;
}
void Jeu::setnbrjoueur(int i){
   nbrdejoueur = i;
}

Plateau Jeu::getplateau(){
    return plateau;
}
void Jeu::setplateau(Plateau pl){
    plateau = pl;
}

Joueur* Jeu::getjoueur(int i){
    return liste[i];
}
void Jeu::setjoueur(Joueur* j, int i){
    liste[i] = j;
}

De Jeu :: getde1(){
    return de1;
}

De Jeu :: getde2(){
    return de2;
}

void Jeu::schedule(){
    while(nbelimine < nbrdejoueur-1){
        this->jouer();
    }
}