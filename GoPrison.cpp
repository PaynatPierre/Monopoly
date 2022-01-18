#include "GoPrison.h"
#include "jeu.h"
#include <iostream>
using namespace std;

GoPrison :: GoPrison(Case *pt): Case ("Aller en Prison", pt){
}

void GoPrison::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arreter sur " << this->getName();
    player->setinprison(true);
    player->settourinprison(0);

    for(int i = 0; i<20; i++){
        player->getPion()->deplacer();
    }

    cout <<   player->getNom() << " est a donc été emmené en prison, il/elle ne passe pas par la case départ et ne reçoit pas 20 000 francs";
}