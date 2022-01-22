#include "ParckGratuit.h"

#include <iostream>
#include <string>

using namespace std;

ParckGratuit::ParckGratuit(Case *ptsuivante, int cagnotte) : Case("parck gratuit", ptsuivante){
    cagnotte=cagnotte;
}
void ParckGratuit::setcagnotte(int i){
    cagnotte=i;
}

void ParckGratuit::addcagnotte(int i){
    cagnotte += i;
}

void ParckGratuit::arreterSur(Joueur* player){
    cout << "Hello je suis un parc gratuit" <<endl;
    cout << player->getNom() << " s'est arreter sur " << getName() << ", la cagnote est de " << cagnotte << " francs"<<endl;
    player->crediter(cagnotte);
    cout << player->getNom() << " gagne donc " << cagnotte << " francs"<<endl;
    cagnotte = 0;
}

int ParckGratuit::getcagnotte() {
    return cagnotte;
}
