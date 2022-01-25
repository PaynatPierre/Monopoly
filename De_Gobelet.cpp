#include "De_Gobelet.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

De :: De(){
    nbFaces = 6;
    valeurs = new int[6];
    for (int i =0; i<nbFaces;i++)
        valeurs[i] = i+1;
}

De :: De(int NbFaces, int* tab_val){
    nbFaces = NbFaces;
    valeurs = new int[NbFaces];
    try{
        for (int i =0; i<nbFaces;i++)
            valeurs[i] = tab_val[i];
    }
    catch(...){
        cout << "Erreur dans les valeurs renseignees veuillez reessayer" << endl;
    }

}

De :: De(const De& d){
    nbFaces = d.nbFaces;
    valeurs = d.valeurs;
}

void De :: setNbFaces(int NbFaces){
    nbFaces = NbFaces;
}

void De :: display(){
    for (int i=0; i<nbFaces;i++)
        cout << valeurs[i] << "\n" << endl;
}

void De :: setValeurs(int* tab_val){
    try{
        for (int i =0; i<nbFaces;i++)
            valeurs[i] = tab_val[i];
    }
    catch(...){
        cout << "Erreur dans les valeurs renseignees veuillez reessayer" << endl;
    }
}

void De :: setValeur(int val){
    valeur_actuelle = val;
}

int De :: getNbFaces(){
    return nbFaces;
}

int* De :: getValeurs(){
    return valeurs;
}

int De :: getValeur(){
    return valeur_actuelle;
}

void De :: lancerDe(){
    srand((unsigned int)time(0));
    int val1;
    int indice1 = rand() % (nbFaces);
    val1 = valeurs[indice1];
    valeur_actuelle = val1;
}