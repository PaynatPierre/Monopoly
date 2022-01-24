#include "Depart.h"

#include <iostream>
#include <string>

using namespace std;

Depart::Depart(int prime, Case* ptsuivante) : Case("Case Depart", ptsuivante){
    prime = prime;
}

void Depart::setprime(int i) {
    prime = i;
}

int Depart::getprime() {
    return prime;
}

void Depart::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arrete.e sur " << m_name << ", il/elle reçoit donc 20 000 francs" << endl;
    cout << "Son solde est donc de" << player->getSolde() << " francs"<<endl;
    player->crediter(20000);
}
