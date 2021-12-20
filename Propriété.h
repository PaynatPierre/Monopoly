
#include <string>
#include "Case.h"
using namespace std;

#ifndef PROPRIETE_H
#define PROPRIETE_H


class Propriété : public Case {
public:
	Joueur* propriétaire;
	int prixAchat;
	int loyer[5];
};

#endif
