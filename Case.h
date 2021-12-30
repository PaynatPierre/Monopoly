#ifndef CASE_H
#define CASE_H

class Case;
class Jeu;
class Joueur;
class Plateau;

#include <string>
#include "Jeu.h"


class Case{
private:
	std::string m_name;
	Case* m_ptsuivante;
	Jeu* m_jeuEnCours;
public:
	Case(std::string, Case*);
	virtual void arreterSur() = 0;
	std::string getName();
	Case* getSuivante();
	void setName(std::string);
	void setSuivante(Case*);
	Jeu* getJeuEnCours();
	void setJeuEnCours(Jeu*);
};

#endif

