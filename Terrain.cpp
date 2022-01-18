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

void Terrain::arreterSur(Joueur* player){
    if(this->getProprietaire() == NULL){
        cout << player->getNom() << " s'est arreter sur " << this->getName() << " qui n'appartient à personne";
        cout << "son prix d'achat est de " << this->getPrixAchat();

        if(this->getPrixAchat() < player->getSolde()){
            cout << player->getNom() << " souhaitez vous l'acheter ? (entrez oui ou non)";
            string reponse = "init";
            while(reponse != "oui" || reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(this->getPrixAchat());
                    player->ajouterAcquisition(this);
                    cout << player->getNom() << " a acheté " << this->getName() << " pour " << this->getPrixAchat() << " francs";
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas acheté " << this->getName();
                }else{
                    cout << "voyez repondre pas oui ou par non";
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter";
        }
    }else{
        cout << player->getNom() << " s'est arreter sur " << this->getName() << " qui appartient à " << this->getProprietaire()->getNom();
        cout << "le loyer est de " << this->getLoyer(this->getnbrmaison()) << " francs";

        //TODO ajouter le cas du loyer nu double
        int payement = min(player->getSolde(),this->getLoyer(this->getnbrmaison()));
        player->debiter(payement);
        this->getProprietaire()->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << this->getProprietaire()->getNom();
    }
}