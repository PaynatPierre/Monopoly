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
    //cout << "Bonjour je suis une case Depart" << endl;
    cout << player->getNom() << " s'est arreté sur " << m_name << ", il/elle reçoit donc 20 000 francs" << endl;
    cout << "il lui reste donc " << player->getSolde() << " francs"<<endl;
    player->crediter(20000);
}
