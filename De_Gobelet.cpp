#include "De_Gobelet.h"
#include "Joueur_Pion.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

De :: De(){
    nbFaces = 6;
    valeurs = new int[6];
    for (int i =0; i<nbFaces;i++)
        valeurs[i] = i+1;
}

De :: De(const int NbFaces, const int* tab_val){
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

void De :: setNbFaces(const int NbFaces){
    nbFaces = NbFaces;
}

void De :: setValeurs(const int* tab_val){
    try{
        for (int i =0; i<nbFaces;i++)
            valeurs[i] = tab_val[i];
    }
    catch(...){
        cout << "Erreur dans les valeurs renseignees veuillez reessayer" << endl;
    }
}

int De :: getNbFaces(){
    return nbFaces;
}

int* De :: setValeurs(){
    return valeurs;
}


bool Gobelet :: doubleValeurs(const int val1, const int val2){
    bool Double;
    Double =   val1 == val2 ;
    return Double;
}


int Gobelet :: getValeursDes(Joueur &J, const De& d1,const De& d2){
    int val1;
    int val2;
    int rst;
    int indice1 = rand() % (d1.nbFaces -1)  + 0;
    int indice2 = rand() % (d2.nbFaces -1)  + 0;
    val1 = d1.valeurs[indice1];
    val2 = d1.valeurs[indice2];
    rst = val1 + val2;
    if (doubleValeurs(val1,val2)){
        int OldNbDouble = J.getNbDouble();
        J.setNbDouble(OldNbDouble +1);
        return rst;
    }
    else{
        return rst;
    }
}

/*
    int val3;
        int val4;
        int indice3 = rand() % (d1.nbFaces -1)  + 0;
        int indice4 = rand() % (d2.nbFaces -1)  + 0;
        val3 = d1.valeurs[indice3];
        val4 = d1.valeurs[indice4];
        rst = rst + val3 + val4;
        if (doubleValeurs(val3,val4)){
            int val5;
            int val6;
            int indice5 = rand() % (d1.nbFaces -1)  + 0;
            int indice6 = rand() % (d2.nbFaces -1)  + 0;
            val5 = d1.valeurs[indice5];
            val6 = d1.valeurs[indice6];
            rst = rst + val5 + val6;
            if (doubleValeurs(val5,val6)){
                return 0; // Va en prison
            }
            else{
                return rst;
            }
        }
        else{
            return rst;
        }
    }

*/