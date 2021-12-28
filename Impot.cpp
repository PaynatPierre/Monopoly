//
// Created by pierr on 28/12/2021.
//

#include "Impot.h"
#include <iostream>
using namespace std;

Impot::Impot(string nom, Case *ptsuivante, int taxe) : Case(nom, ptsuivante){
    this->taxe=taxe;
}

void Impot::settaxe(int i) {
    this->taxe = i;
}

int Impot::gettaxe() {
    return taxe;
}

void Impot::jouerimpot() {
//    TODO debiter le montant de la taxe
}
