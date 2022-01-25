#include "Terrain.h"

#include <string>
#include <iostream>

using namespace std;


Terrain :: Terrain(const string& color, const string& name,  Case* ptsuivante, int prixAchat, int *loyer,int prixm) : Propriete(name, ptsuivante, prixAchat, loyer){
    couleur = color;
    prixmaison = prixm;
    nbrmaison = 0;
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
    if(m_proprietaire == NULL){
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " qui n'appartient a personne"<< endl;
        cout << "son prix d'achat est de " << m_prixAchat<< endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " Souhaitez-vous l'acheter ? (entrez oui ou non)"<< endl;
            string reponse = "init";
            while(reponse != "oui" && reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    (*player)-= m_prixAchat;
                    (*player)+= this;
                    m_proprietaire = player;
                    cout << player->getNom() << " a achete " << m_name << " pour " << m_prixAchat << " francs"<< endl;
                    cout << "Il lui reste donc " << player->getSolde() << " francs" <<endl;
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas achete " << m_name<< endl;
                    
                }else{
                    cout << "Veuillez repondre pas oui ou par non"<< endl;
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter"<< endl;
        }
    }else if(m_proprietaire->getPion()->getNom() == player->getPion()->getNom()){
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " qui lui appartient " << endl;
    }else{
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " qui appartient a " << m_proprietaire->getNom()<< endl;
        cout << "le loyer est de " << m_loyer[nbrmaison] << " francs"<< endl;

        int payement = min(player->getSolde(),m_loyer[nbrmaison]);
        (*player)-=payement;
        (*m_proprietaire)+=payement;

        cout << player->getNom() << " paie " << payement << " francs a " << m_proprietaire->getNom()<< endl;
        cout << "Il lui reste donc " << player->getSolde() << " francs" <<endl;
    }
}