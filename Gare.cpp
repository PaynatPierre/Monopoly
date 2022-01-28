#include "Gare.h"
#include <iostream>
#include <string>
using namespace std;

Gare::Gare(std::string nom, Case* ptsuivant, int prixachat, int loyer[]) : Propriete(nom, ptsuivant, prixachat, loyer){

}

void Gare::arreterSur(Joueur* player){
    if(m_proprietaire == NULL){
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " qui n'appartient a personne" << endl;
        cout << "Son prix d'achat est de " << m_prixAchat << " francs" << endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " Souhaitez-vous l'acheter ? (entrez oui ou non)" << endl;
            string reponse = "init";
            while(reponse != "oui" && reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    (*player)-= m_prixAchat;
                    (*player)+= this;
                    player->addgare();
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
        cout << "Le loyer est de " << getLoyer(m_proprietaire->getnbgare()) << " francs"<< endl;
        int payement = min(player->getSolde(),getLoyer(m_proprietaire->getnbgare()));
        (*player)-=payement;
        (*m_proprietaire)+=payement;

        cout << player->getNom() << " paie " << payement << " francs a " << m_proprietaire->getNom()<< endl;
    }
}