//
// Created by pierr on 29/12/2021.
//

#include "ParckGratuit.h"
#include "jeu.h"
#include <iostream>
using namespace std;

ParckGratuit::ParckGratuit(Case *ptsuivante, int cagnotte) : Case("parck gratuit", ptsuivante){
    this->cagnotte=cagnotte;
}
void ParckGratuit::setcagnotte(int i){
    this->cagnotte=i;
}

void ParckGratuit::addcagnotte(int i){
    this->cagnotte += i;
}

void ParckGratuit::arreterSur(){

}

int ParckGratuit::getcagnotte() {
    return cagnotte;
}

void ParckGratuit::jouerparckgratuit(Joueur* player){
    cout << player->getNom() << " s'est arreter sur " << this->getName() << ", la cagnote est de " << this->cagnotte << " francs";
    player->crediter(this->cagnotte);
    cout << player->getNom() << " gagne donc " << this->cagnotte << " francs";
    this->cagnotte = 0;
}
