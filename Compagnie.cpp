#include "Compagnie.h"

#include <iostream>
#include <string>

using namespace std;


Compagnie :: Compagnie(const string& name,  Case* ptsuivante, int prixAchat, int loyer[6]) : Propriete(name, ptsuivante, prixAchat, loyer){
}

void Compagnie::arreterSur(Joueur* player){
     
   if(m_proprietaire == NULL){
        //cout << "Hello je suis une case compagnie" <<endl;
        cout << player->getNom() << " s'est arreter sur " << m_name << " dont personne ne possède la carte" << endl;
        cout << "son prix d'achat est de " << m_prixAchat << endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " souhaitez vous l'acheter ? (entrez oui ou non)" << endl;
            string reponse = "init";
            while(reponse != "oui" && reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(m_prixAchat);
                    player->ajouterAcquisition(this);
                    player->addCompagnie();
                    cout << player->getNom() << " a acheté " << m_name << " pour " << m_prixAchat << " francs" << endl;
                    cout << "il lui reste donc " << player->getSolde() << " francs" <<endl;
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas acheté " << m_name << endl;
                }else{
                    cout << "veuillez repondre pas oui ou par non" << endl;
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter" << endl;
        }
    }else{
        cout << player->getNom() << " s'est arreter sur " << m_name << " qui appartient à " << m_proprietaire->getNom() << endl;
        if (m_proprietaire->getNbCompagnie() == 1){
        cout << "le loyer est de " << 400  << " francs" << endl;
        int payement = min(player->getSolde(), 400);
        player->debiter(payement);
        m_proprietaire->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs à " << m_proprietaire->getNom() << endl;
        }else{
         cout << "le loyer est de " << 1000  << " francs" << endl;  
        int payement = min(player->getSolde(), 1000);
        player->debiter(payement);
        m_proprietaire->crediter(payement);
        cout << player->getNom() << " paie " << payement << " francs à " << m_proprietaire->getNom() << endl;                  
        }

    }
}