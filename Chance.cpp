#include "Chance.h"
#include "Jeu.h"
#include <string>
#include <iostream>
using namespace std;

Chance::Chance(string nom, Case* ptsuivante) : Case(nom, ptsuivante){
}

void arreterSur(){

}

void Chance::jouerChance(){
    int indice;
    string carteTire;
    indice = rand() % 16;
    carteTire = m_carteChance[indice];
    /*Jeu *jeuEnCours(0);
    jeuEnCours = getJeuEnCours();
    (*jeuEnCours).toursuivant();*/
}

string Chance::getCarteChance(int i){
    return m_carteChance[i];
}

void Chance::setCarteChance(int i, string name){
    m_carteChance[i] = name;
}




#endif
