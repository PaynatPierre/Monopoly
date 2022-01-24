#ifndef PROPRIETE_H
#define PROPRIETE_H


#include <string>

#include "Case.h"

class Joueur;


class Propriete : public Case {
protected: 
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
