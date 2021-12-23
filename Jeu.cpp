//
// Created by pierr on 15/12/2021.
//

#include "Jeu.h"



Jeu::Jeu(int nbrplayer, Joueur **players) : plateau(), des[0](), des[1](), goblet(){
    this->nbrdejoueur = nbrplayer;
//    this->liste = players
    this->plateau.creercase();
    this->tourdejeu = 1;
//  TODO shuffle la liste avant de commencer
    this->liste[0].jouer();
}

int Jeu::gettourdejeu(){
    return this->tourdejeu;
}
void Jeu::settourdejeu(int i){
    this->tourdejeu = i;
}
void Jeu::toursuivant(){
    this->tourdejeu = this->tourdejeu +1;
}

int Jeu::getnbrjoueur(){
    return this->nbrdejoueur;
}
void Jeu::setnbrjoueur(int i){
   this->nbrdejoueur = i;
}

Plateau Jeu::getplateau(){
    return this->plateau;
}
void Jeu::setplateau(Plateau pl){
    this->plateau = pl;
}

Joueur* Jeu::getjoueur(int i){
    return this->liste[i];
}
void Jeu::setjoueur(Joueur* j, int i){
    this->liste[i] = j;
}

Gobelet Jeu::getgobelet(){
    return this->goblet;
}
void Jeu::setgobelet(Gobelet g){
    this->goblet = g
}

De Jeu::getde(int i){
    return des[i];
}
void Jeu::setde(De d, int i){
    this->des[i] = d;
}