#ifndef CODEPROJET4_TERRAIN_H
#define CODEPROJET4_TERRAIN_H

#include <string>
#include "Case.h"
#include "Propriete.h"
#include "Joueur_Pion.h"

class Terrain: public Propriete{

private:
    std::string couleur;
    int nbrmaison;
    int prixmaison;
protected:

public:
    Terrain(const std::string&, const std::string&,  Case*, int, int*, int);
    std::string getcouleur();
    void setcouleur(std::string);
    void setnbrmaison(int);
    int getnbrmaison();
    int getprixm_h();
    void setprixm_h(int);
    void arreterSur(Joueur*);
};

#endif