
#include <string>
#include "Case.h"
using namespace std;

#ifndef PROPRIETE_H
#define PROPRIETE_H


class Propri�t� : public Case {
public:
	Joueur* propri�taire;
	int prixAchat;
	int loyer[5];
};

#endif
