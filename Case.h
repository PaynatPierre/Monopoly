#ifndef CASE_H
#define CASE_H

class Case;
class Joueur;
class Plateau;

#include <string>


class Case{
private:
	std::string m_name;
	Case* m_ptsuivante;
	/*Jeu* m_jeuEnCours;*/
public:
	Case(std::string, Case*);
	Case(const Case&);
	std::string getName();
	Case* getSuivante();
	void setName(std::string);
	void setSuivante(Case*);
	/*Jeu* getJeuEnCours();
	void setJeuEnCours(Jeu*);*/
	virtual void arreterSur(Joueur*) = 0;
};

#endif

