#include "Compagnie.h"
#include "Propriete.h"
#include <iostream>
using namespace std;


Compagnie :: Compagnie(const string& name,  Case* ptsuivante,int nbcomp, int prixAchat, int loyer[6]) : Propriete(name, ptsuivante, prixAchat, loyer){
    nbcompagnies =  nbcomp;
}


int Compagnie::getnb_compagnie() {
    return nbcompagnies;
}

void Compagnie::setnb_compagnie(int c) {
    nbcompagnies = c;
}


void Compagnie::jouerCompagnie()
{

}

void Compagnie::arreterSur(){
    
}