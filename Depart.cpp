#include "Depart.h"
#include "jeu.h"
using namespace std;

void Depart::jouerDepart(){
    

    Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();
}
