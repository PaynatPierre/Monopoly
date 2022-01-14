#include "Impot.h"
#include <iostream>
#include <string>
using namespace std;

Impot::Impot(string Nom, Case *Ptsuivante, int Taxe) : Case(Nom, Ptsuivante){
    taxe=Taxe;
}

void Impot::arreterSur(){

}

void Impot::settaxe(int i) {
    taxe = i;
}

int Impot::gettaxe() {
    return taxe;
}

void Impot::jouerimpot() {
//    TODO debiter le montant de la taxe
}
