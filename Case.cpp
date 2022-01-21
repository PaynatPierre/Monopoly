#include <iostream>
#include <string>
#include <math.h>
#include "Case.h"

using namespace std;

Case::Case(string name, Case* ptsuivante): m_name(name) {
	m_ptsuivante = ptsuivante;
}

Case :: Case(const Case& c){
	m_name = c.m_name;
	m_ptsuivante = c.m_ptsuivante;
}

string Case::getName() {
	return m_name;
}

void Case::setName(string n) {
	m_name = n;
}

Case* Case::getSuivante() {
	return m_ptsuivante;
}

void Case::setSuivante(Case* ptsuivante) {
	m_ptsuivante = ptsuivante;	
}

/*Jeu* Case::getJeuEnCours() {
	return m_jeuEnCours;
}

void Case::setJeuEnCours(Jeu* jeuEnCours) {
	m_jeuEnCours = jeuEnCours;	
}*/
