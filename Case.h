#ifndef CASE_H
#define CASE_H


class Joueur;

#include <string>


class Case{
protected:
	std::string m_name;
	Case* m_ptsuivante;
public:
	Case(std::string, Case*);
	Case(const Case&);
	std::string getName();
	Case* getSuivante();
	void setName(std::string);
	void setSuivante(Case*);
	virtual void arreterSur(Joueur*) = 0;
};

#endif