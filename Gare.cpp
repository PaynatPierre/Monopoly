#include "Gare.h"
#include "Jeu.h"
#include <iostream>
using namespace std;

Gare::Gare(std::string nom, Case* ptsuivant, int prixachat, int loyer[]) : Propriete(nom, ptsuivant, prixachat, loyer){

}

void Gare::arreterSur(Joueur* player){

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
                    player->addgare();
                    cout << player->getNom() << " a acheté " << this->getName() << " pour " << this->getPrixAchat() << " francs";
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas acheté " << this->getName();
                }else{
                    cout << "veuillez repondre pas oui ou par non";
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter";
        }
    }else{
        cout << player->getNom() << " s'est arreter sur " << this->getName() << " qui appartient à " << this->getProprietaire()->getNom();
        cout << "le loyer est de " << this->getLoyer(this->getProprietaire()->getnbgare()) << " francs";
        int payement = min(player->getSolde(),this->getLoyer(this->getProprietaire()->getnbgare()));
        player->debiter(payement);
        this->getProprietaire()->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << this->getProprietaire()->getNom();
    }
}
