#include <iostream>
#include <string>
#include "Propriete.h"
using namespace std;

Propriete::Propriete(string name, Case* ptsuivante, int prixAchat, int loyer[5]) : Case(name, ptsuivante), m_prixAchat(prixAchat) {
    m_loyer[5] = loyer[5];
}

int Propriete::getPrixAchat(){
	return m_prixAchat;
}

Joueur* Propriete::getProprietaire(){
	return m_proprietaire;
}

int Propriete::getLoyer(int i){
	return m_loyer[i];
}

void Propriete::setPrixAchat(int prixAchat) {
	m_prixAchat = prixAchat;
}

void Propriete::setProprietaire(Joueur* proprietaire) {
	m_proprietaire = proprietaire;
}

void Propriete::setLoyer(int i, int loyer) {
	m_loyer[i] = loyer;
}


