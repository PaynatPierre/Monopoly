#include "Communaute.h"
#include "jeu.h"
using namespace std;


void Communaute::jouerCommunaute(){
    int indice;
    string carteTire;
    indice = rand() % 16;
    carteTire = m_carteCommunaute[indice];
    Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();
}

string Communaute::getCarteCommunaute(int i){
    return m_carteCommunaute[i];
}

void Communaute::setCarteCommunaute(int i, string name){
    m_carteCommunaute[i] = name;
}