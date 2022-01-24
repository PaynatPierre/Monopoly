#include "ParckGratuit.h"

#include <iostream>
#include <string>

using namespace std;

ParckGratuit::ParckGratuit(Case *ptsuivante, int cagnotte) : Case("parck_gratuit", ptsuivante){
    this->cagnotte=cagnotte;
}
void ParckGratuit::setcagnotte(int i){
    cagnotte=i;
}

void ParckGratuit::addcagnotte(int i){
    cagnotte += i;
}

void ParckGratuit::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arrete.e sur " << getName() << ", la cagnote est de " << cagnotte << " francs"<<endl;
    player->crediter(cagnotte);
    cout << player->getNom() << " gagne donc " << cagnotte << " francs"<<endl;
    cout << "Il lui reste donc " << player->getSolde() << " francs" <<endl;
    cagnotte = 0;
}

int ParckGratuit::getcagnotte() {
    return cagnotte;
}
