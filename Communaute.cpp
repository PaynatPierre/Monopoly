#include "Communaute.h"
#include "Jeu.h"
#include "ParckGratuit.h"
#include <string>
#include <iostream>
using namespace std;

Communaute::Communaute(string nom, Case* ptsuivante) : Case(nom, ptsuivante){
}

void Communaute::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arreter sur " << this->getName();
    int i = rand()%2;
    if(i == 0){
        cout << "pas de chance, " << player->getNom() << " doit payer 20 000 francs à la banque";
        int payement = min(player->getSolde(), 20000);
        cout << player->getNom() << " paie " << payement << " francs à la banque";
        
        player->debiter(payement);

        Case * c = this;
        while(c->getName() != "parck gratuit"){
            c = c->getSuivante();
        }

        ParckGratuit* p = (ParckGratuit*)c;
        p->addcagnotte(payement);

    }else{
        cout << "cout de chance, " << player->getNom() << " gagne 20 000 francs";
        player->crediter(20000);
    }
}

string Communaute::getCarteCommunaute(int i){
    return m_carteCommunaute[i];
}

void Communaute::setCarteCommunaute(int i, string name){
    m_carteCommunaute[i] = name;
}