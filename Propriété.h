#ifndef PROPRIETE_H
#define PROPRIETE_H

#include <string>
#include "Case.h"


class Propriété : public Case {
private: 
	int m_prixAchat;
	int m_loyer[5];
public:
	Propriété(int prixAchat, int loyer[5]);
	Joueur* getPropriétaire;
};

#endif
