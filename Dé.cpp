#include "Dé.h"
#include <iostream>
#include <string>
using namespace std;

Dé :: Dé(){
    nbFaces = 6;
    valeurs = new int[6];
    for (int i =0; i<nbFaces;i++)
        valeurs[i] = i+1;
}

Dé :: Dé(const int NbFaces, const int* tab_val){
    nbFaces = NbFaces;
    valeurs = new int[NbFaces];
    try{
        for (int i =0; i<nbFaces;i++)
            valeurs[i] = tab_val[i];
    }
    catch(...){
        cout << "Erreur dans les valeurs renseignées veuillez réessayer" << endl;
    }

}

void Dé :: setNbFaces(const int NbFaces){
    nbFaces = NbFaces;
}

void Dé :: setValeurs(const int* tab_val){
    try{
        for (int i =0; i<nbFaces;i++)
            valeurs[i] = tab_val[i];
    }
    catch(...){
        cout << "Erreur dans les valeurs renseignées veuillez réessayer" << endl;
    }
}

int Dé :: getNbFaces(){
    return nbFaces;
}

int* Dé :: setValeurs(){
    return valeurs;
}
