#include "Propriete.h"

#include <iostream>
#include <string>

using namespace std;

Propriete::Propriete(string name, Case* ptsuivante, int prixAchat, int *loyer) : Case(name, ptsuivante), m_prixAchat(prixAchat) {
    for (int i =0; i<6;i++)
        m_loyer[i] = loyer[i];
	m_proprietaire = NULL;
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

void Propriete :: hello(){
	cout << "hello je suis une propriété" << endl;
}
void Propriete::setProprietaire(Joueur* proprietaire) {
	m_proprietaire = proprietaire;
}

void Propriete::setLoyer(int i, int loyer) {
	m_loyer[i] = loyer;
}


