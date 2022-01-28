#include "Impot.h"
#include "ParckGratuit.h"
#include <string>
#include <iostream>
using namespace std;

Impot::Impot(string Nom, Case *Ptsuivante, int Taxe) : Case(Nom, Ptsuivante){
    taxe=Taxe;
}

void Impot::arreterSur(Joueur* player){
    if(m_name == "taxe de luxe"){
        int taxe = 10000;
    }else{
        int taxe = 20000;
    }

    cout << player->getNom() << " s'est arrete.e sur " << m_name << ", la taxe est de " << taxe <<" francs"<< endl;
    int payement = min(player->getSolde(), taxe);
    (*player)-=payement;
    cout << player->getNom() << " paie " << payement << " francs de taxe"<< endl;
    cout << "Il lui reste donc " << player->getSolde() << " francs" <<endl;

    Case* c = this;
    while(c->getName() != "parck_gratuit"){
        c = c->getSuivante();
    }

    ParckGratuit* p = (ParckGratuit*)c;
    p->addcagnotte(payement);
}

void Impot::settaxe(int i) {
    taxe = i;
}

int Impot::gettaxe() {
    return taxe;
}