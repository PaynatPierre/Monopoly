#include "Depart.h"
#include "jeu.h"
#include <iostream>
using namespace std;

Depart::Depart(int prime, Case* ptsuivante) : Case("Case Depart", ptsuivante){
    this->prime = prime;
}

void Depart::setprime(int i) {
    this->prime = i;
}

int Depart::getprime() {
    return prime;
}

void Depart::jouerDepart(){
    Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();
}

void Depart::arreterSur(){
    
}
