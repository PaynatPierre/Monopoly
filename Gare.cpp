#include "Gare.h"

#include <iostream>
#include <string>

using namespace std;

Gare::Gare(std::string nom, Case* ptsuivant, int prixachat, int loyer[]) : Propriete(nom, ptsuivant, prixachat, loyer){

}

void Gare ::hello(){
    cout << "Hello je suis une gare"<< endl;
}

void Gare::arreterSur(Joueur* player){
    //cout << "Hello je suis une gare" <<endl;
    if(m_proprietaire == NULL){
        cout << player->getNom() << " s'est arreter sur " << m_name << " qui n'appartient a personne" << endl;
        cout << "son prix d'achat est de " << m_prixAchat << " francs" << endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " souhaitez vous l'acheter ? (entrez oui ou non)" << endl;
            string reponse = "init";
            while(reponse != "oui" && reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(m_prixAchat);
                    player->ajouterAcquisition(this);
                    player->addgare();
                    cout << player->getNom() << " a achete " << m_name << " pour " << m_prixAchat << " francs"<< endl;
                    cout << "il lui reste donc " << player->getSolde() << " francs" <<endl;

                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas achete " << m_name<< endl;
                }else{
                    cout << "veuillez repondre pas oui ou par non"<< endl;
                }
            }
            cout << "test103" <<endl;
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter"<< endl;
        }
    }else{
        cout << player->getNom() << " s'est arreter sur " << m_name << " qui appartient a " << m_proprietaire->getNom()<< endl;
        cout << "le loyer est de " << getLoyer(m_proprietaire->getnbgare()) << " francs"<< endl;
        int payement = min(player->getSolde(),getLoyer(m_proprietaire->getnbgare()));
        player->debiter(payement);
        m_proprietaire->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs a " << m_proprietaire->getNom()<< endl;
    }
}
