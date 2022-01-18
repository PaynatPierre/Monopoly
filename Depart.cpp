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

void Depart::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arreté sur " << this->getName() << ", il/elle reçoit donc 20 000 francs";
    player->crediter(20000);
}
