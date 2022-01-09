#ifndef PROPRIETE_H
#define PROPRIETE_H


class Jeu;
class Joueur;
class Plateau;


#include <string>
#include "Case.h"
#include "Joueur_Pion.h"


class Propriete : public Case {
private: 
	int m_prixAchat;
	int m_loyer[6];
    Joueur* m_proprietaire;
public:
	Propriete(std::string,  Case*, int, int *);
	int getPrixAchat();
	int getLoyer(int i);
	Joueur* getProprietaire();
	void setPrixAchat(int);
	void setLoyer(int, int);
	void setProprietaire(Joueur*);
};

#endif
