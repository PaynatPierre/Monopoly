#ifndef CASE_H
#define CASE_H

#include <string>
#include "Jeu.h"
using namespace std;


class Case {
private:
	string name;
	Case* ptsuivante;
public:
	Jeu* jeuEnCours;
	virtual void arreterSur() = 0;
	string getName();
	Case getSuivante();
	string setName(string n);
	string SetSuivante();

};

#endif

