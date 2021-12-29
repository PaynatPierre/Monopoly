//
// Created by emma on 24/12/2021.
//

#ifndef CODEPROJET4_TERRAIN_H
#define CODEPROJET4_TERRAIN_H
#include <iostream>
using namespace std;

class Terrain {

private:
    string couleur;
    int nbrmaison;
    int prixmaison[2];
protected:

public:
    Terrain(const string& color, const string& name,  Case* ptsuivante, const int prixAchat, const int loyer[5], const int prixm[2]);
    string getcouleur();
    void setcouleur(string color);
    void jouerTerrain();
    void setnbrmaison(int i);
    int getnbrmaison();
    int getprixmaison();
    int getprixhotel();
    void setprixmaison(int i);
    void setprixhotel(int i);
};


#endif //CODEPROJET4_TERRAIN_H
