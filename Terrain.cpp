#include "Terrain.h"

#include <string>
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
    return couleur;
}
void Terrain::setcouleur(string color){
    couleur = color;
}

void Terrain::arreterSur(Joueur* player){
    cout << "Hello je suis une case Terrain" << endl;
    if(m_proprietaire == NULL){
        cout << player->getNom() << " s'est arreter sur " << m_name << " qui n'appartient à personne"<< endl;
        cout << "son prix d'achat est de " << m_prixAchat<< endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " souhaitez vous l'acheter ? (entrez oui ou non)"<< endl;
            string reponse = "init";
            while(reponse != "oui" || reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(m_prixAchat);
                    player->ajouterAcquisition(this);
                    cout << player->getNom() << " a acheté " << m_name << " pour " << m_prixAchat << " francs"<< endl;
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas acheté " << m_name<< endl;
                }else{
                    cout << "voyez repondre pas oui ou par non"<< endl;
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter"<< endl;
        }
    }else{
        cout << player->getNom() << " s'est arreter sur " << m_name << " qui appartient à " << m_proprietaire->getNom()<< endl;
        cout << "le loyer est de " << getLoyer(getnbrmaison()) << " francs"<< endl;

        //TODO ajouter le cas du loyer nu double
        int payement = min(player->getSolde(),getLoyer(getnbrmaison()));
        player->debiter(payement);
        m_proprietaire->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << m_proprietaire->getNom()<< endl;
    }
}