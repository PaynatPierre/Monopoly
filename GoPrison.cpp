#include "GoPrison.h"

#include <string>
#include <iostream>
using namespace std;

GoPrison :: GoPrison(Case *pt): Case ("Aller en Prison", pt){
}

void GoPrison::arreterSur(Joueur* player){
    //cout << "Hello je suis une Case GoPrison" <<endl;
    cout << player->getNom() << " s'est arreter sur " << m_name<< endl;
    player->setinprison(true);
    player->settourinprison(0);

    for(int i = 0; i<20; i++){
        player->getPion()->deplacer();
    }

    cout <<   player->getNom() << " est a donc été emmené en prison, il/elle ne passe pas par la case départ et ne reçoit pas 20 000 francs"<< endl;
}