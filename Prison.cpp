#include "Prison.h"
#include "jeu.h"
using namespace std;

Prison::Prison(Case *ptsuivante) : Case("prison", ptsuivante){
}

void Prison::jouerPrison(){

    Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();
}

void Prison::arreterSur(){
    
}