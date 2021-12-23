#include "Prison.h"
#include "jeu.h"
using namespace std;


void Prison::jouerPrison(){

    Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();
}
