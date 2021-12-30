#ifndef CODEPROJET4_TERRAIN_H
#define CODEPROJET4_TERRAIN_H


class Case;
class Jeu;
class Joueur;
class Plateau;


#include <string>
#include "Case.h"

class Terrain {

private:
    std::string couleur;
    int nbrmaison;
    int prixmaison[2];
protected:

public:
    Terrain(const std::string& color, const std::string& name,  Case* ptsuivante, const int prixAchat, const int loyer[5], const int prixm[2]);
    std::string getcouleur();
    void setcouleur(std::string color);
    void jouerTerrain();
    void setnbrmaison(int i);
    int getnbrmaison();
    int getprixmaison();
    int getprixhotel();
    void setprixmaison(int i);
    void setprixhotel(int i);
};


#endif