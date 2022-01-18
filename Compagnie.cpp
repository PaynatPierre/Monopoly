#include "Compagnie.h"
#include "Propriete.h"
#include <iostream>
using namespace std;


Compagnie :: Compagnie(const string& name,  Case* ptsuivante, int prixAchat, int loyer[6]) : Propriete(name, ptsuivante, prixAchat, loyer){
}





void Compagnie::jouerCompagnie(Joueur* player){

   if(this->getProprietaire() == NULL){
        cout << player->getNom() << " s'est arreter sur " << this->getName() << " dont personne ne possède la carte";
        cout << "son prix d'achat est de " << this->getPrixAchat();

        if(this->getPrixAchat() < player->getSolde()){
            cout << player->getNom() << " souhaitez vous l'acheter ? (entrez oui ou non)";
            string reponse = "init";
            while(reponse != "oui" || reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(this->getPrixAchat());
                    player->ajouterAcquisition(this);
                    player->addCompagnie();
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
        if (this->getProprietaire()->getNbCompagnie() == 1){
        cout << "le loyer est de " << 400  << " francs";
        int payement = min(player->getSolde(), 400);
        player->debiter(payement);
        this->getProprietaire()->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << this->getProprietaire()->getNom();
        }else{
         cout << "le loyer est de " << 1000  << " francs";  
        int payement = min(player->getSolde(), 1000);
        player->debiter(payement);
        this->getProprietaire()->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << this->getProprietaire()->getNom();                  
        }

        //TODO ajouter le cas du loyer nu double

    }
}

void Compagnie::arreterSur(){
    
}