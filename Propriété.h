#ifndef PROPRIETE_H
#define PROPRIETE_H

#include <string>
#include "Case.h"
#include "Joueur_Pion.h"


class Propriete : public Case {
private: 
	int m_prixAchat;
	int m_loyer[5];
	Joueur* m_proprietaire;	
public:
	Propriete(string name,  Case* ptsuivante, int prixAchat, int loyer[5]);
	int getPrixAchat();
	int getLoyer(int i);
	Joueur* getProprietaire();
	void setPrixAchat(int prixAchat);
	void setLoyer(int i, int loyer);
	void setProprietaire(Joueur* proprietaire);
};

#endif
