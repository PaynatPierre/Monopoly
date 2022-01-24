#include "Chance.h"
#include "ParckGratuit.h"

#include <string>
#include <iostream>

using namespace std;

Chance::Chance(string nom, Case* ptsuivante) : Case(nom, ptsuivante){
}

void Chance::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arrete.e sur " << m_name << endl;
    int i = rand()%2;
    if(i == 0){
        cout << "pas de chance, " << player->getNom() << " doit payer 20 000 francs a la banque" << endl;
        int payement = min(player->getSolde(), 20000);
        cout << player->getNom() << " paie " << payement << " francs a la banque" << endl;
        
        player->debiter(payement);

        Case * c = this;
        while(c->getName() != "parck gratuit"){
            c = c->getSuivante();
        }

        ParckGratuit* p = (ParckGratuit*)c;
        p->addcagnotte(payement);

    }else{
        cout << "coup de chance, " << player->getNom() << " gagne 20 000 francs" << endl;
        player->crediter(20000);
    }
}

string Chance::getCarteChance(int i){
    return m_carteChance[i];
}

void Chance::setCarteChance(int i, string name){
    m_carteChance[i] = name;
}




