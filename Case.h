#ifndef CASE_H
#define CASE_H

#include <string>
#include "Jeu.h"
using namespace std;


class Case {
private:
	string m_name;
	Case* m_ptsuivante;
	Jeu *m_jeuEnCours;
public:
	Case(string m_name, Case* m_ptsuivante);
	virtual void arreterSur() = 0;
	string getName();
	Case* getSuivante();
	void setName(string n);
	void SetSuivante(Case* ptsuivante);
	Jeu* getJeuEnCours();
	void setJeuEnCours(Jeu* jeuEnCours);

};

#endif

