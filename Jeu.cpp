//
// Created by pierr on 15/12/2021.
//

#include "Jeu.h"
#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"


Jeu :: Jeu(int t,int n, Joueur **l, De&d1, De&d2): plateau(), gobelet(), de1(d1), de2(d2){
    tourdejeu = t;
    nbrdejoueur = n;
    for (int i=0; i<6 ; i++)
        liste[i] = l[i];
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
De Jeu:: getde1(){

}
De Jeu:: getde2(){

}
void Jeu:: setde1(De&){

}
void Jeu:: setde2(De&){

}