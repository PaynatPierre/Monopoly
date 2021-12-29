//
// Created by emma on 24/12/2021.
//

#include "Terrain.h"
#include "Propriété.h"
#include <iostream>
using namespace std;


Terrain::Terrain(const string& color, const string& name,  Case* ptsuivante, const int prixAchat, const int loyer[5], const int prixm[2]) : Propriété(name, ptsuivante, prixAchat, loyer){
    this->couleur = color;
    this->prixmaison=prixm;
}

void Terrain::setnbrmaison(int i) {
    this->nbrmaison = i;
}

int Terrain::getnbrmaison() {
    return nbrmaison;
}

int Terrain::getprixmaison() {
    return prixmaison[0];
}

int Terrain::getprixhotel() {
    return prixmaison[1];
}

void Terrain::setprixmaison(int i) {
    prixmaison[0] = i;
}

void Terrain::setprixhotel(int i) {
    prixmaison[1] = i;
}

string Terrain::getcouleur(){
    return this->couleur;
}
void Terrain::setcouleur(string color){
    this->couleur = color;
}

void Terrain::jouerTerrain()
{
    if Propriete::getproprietaire() == none :  //à modifier, comment écrire condition "si il n'y a pas de propriétaire" ? 
        bool yesno(False);
        cin >> "Voulez-vous acheter ce Terrain ?" >> yesno >> endl; //le joueur rentre son choix
        // est-ce que le code va attendre que la personne rentre sa commande pour lancer la suite ?
        if yesno :
            Joueur::debiter(prixachat) ; // le joueur paye pour acheter 
            Joueur::ajouterAcquisition(Propriete*); //à modifier : le joueur devient propriétaire
        else : 
        cout << "Tu as choisi de ne pas acheter" << endl;
    else :
        Joueur::debiter(loyer[0]) ;  //à modifier, le joueur paie le loyer je mets loyer[0] au pif .. est ce que loyer compte le loyer du terrain sans maison ? Et si le proprio a tous les terrains de cette couleur ? 
        Joueur::m_proprietaire::crediter(loyer[0])  ;   //à modifier, le propriétaire reçoit l'argent du loyer

}
