#include "Terrain.h"
#include "Propriete.h"
#include <iostream>
using namespace std;


Terrain :: Terrain(const string& color, const string& name,  Case* ptsuivante, int prixAchat, int loyer[6],int prixm) : Propriete(name, ptsuivante, prixAchat, loyer){
    couleur = color;
    prixmaison = prixm;
}

void Terrain::setnbrmaison(int i) {
    nbrmaison = i;
}

int Terrain::getnbrmaison() {
    return nbrmaison;
}

int Terrain::getprixm_h() {
    return prixmaison;
}

void Terrain::setprixm_h(int p) {
    prixmaison = p;
}

string Terrain::getcouleur(){
    return this->couleur;
}
void Terrain::setcouleur(string color){
    this->couleur = color;
}

void Terrain::jouerTerrain()
{
    if (Propriete::getproprietaire() == none) :  //à modifier, comment écrire condition "si il n'y a pas de propriétaire" ? 
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

void arreterSur(){
    
}