//
// Created by pierr on 29/12/2021.
//

#include "ParckGratuit.h"
#include <iostream>
using namespace std;

ParckGratuit::ParckGratuit(Case *ptsuivante, int cagnotte) : Case("parck gratuit", ptsuivante){
    this->cagnotte=cagnotte;
}
void ParckGratuit::setcagnotte(int i){
    this->cagnotte=i;
}

void arreterSur(){

}

int ParckGratuit::getcagnotte() {
    return cagnotte;
}

void ParckGratuit::jouerparckgratuit() {
//    TODO jouer parck gratuit
}
