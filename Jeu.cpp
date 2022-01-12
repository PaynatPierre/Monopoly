//
// Created by pierr on 15/12/2021.
//

#include "Jeu.h"
#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"


Jeu :: Jeu (const De& d1, const De& d2, Joueur ** liste_de_joueurs, int t = 0, int bonjour = 8){
    nbrdejoueur = bonjour;
    tourdejeu = t;
    de1 = new De(d1);
    de2 = new De(d2);
    for (int i=0; i<6 ; i++)
        liste[i] = liste_de_joueurs[i];
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

Gobelet Jeu::getgobelet(){
    return gobelet;
}
void Jeu::setgobelet(Gobelet g){
    gobelet = g;
}
De Jeu :: getde1(){
    return *de1;
}

De Jeu :: getde2(){
    return *de2;
}

void Jeu :: setde1(De& d1){
    delete[] de1;
    de1 = new De(d1);
}
void Jeu:: setde2(De& d2){
    delete[] de2;
    de2 = new De(d2);
}