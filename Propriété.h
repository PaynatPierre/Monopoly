#ifndef PROPRIETE_H
#define PROPRIETE_H

#include <string>
#include "Case.h"


class Propriété : public Case {
public:
	Joueur* propriétaire;
	int prixAchat;
	int loyer[5];
};

#endif
