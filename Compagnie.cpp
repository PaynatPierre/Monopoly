#include "Compagnie.h"

#include <iostream>
#include <string>

using namespace std;


Compagnie :: Compagnie(const string& name,  Case* ptsuivante, int prixAchat, int loyer[6]) : Propriete(name, ptsuivante, prixAchat, loyer){
}

void Compagnie::arreterSur(Joueur* player){
     
   if(m_proprietaire == NULL){
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " dont personne ne possede la carte" << endl;
        cout << "Son prix d'achat est de " << m_prixAchat << endl;

        if(m_prixAchat < player->getSolde()){
            cout << player->getNom() << " Souhaitez-vous l'acheter ? (entrez oui ou non)" << endl;
            string reponse = "init";
            while(reponse != "oui" && reponse != "non"){
                cin >> reponse;
                if(reponse == "oui"){
                    player->debiter(m_prixAchat);
                    player->ajouterAcquisition(this);
                    player->addCompagnie();
                    m_proprietaire = player;
                    cout << player->getNom() << " a achete " << m_name << " pour " << m_prixAchat << " francs" << endl;
                    cout << "Il lui reste donc " << player->getSolde() << " francs" <<endl;
                }else if(reponse == "non"){
                    cout << player->getNom() << " n'a pas achete " << m_name << endl;
                }else{
                    cout << "Veuillez repondre pas oui ou par non" << endl;
                }
            }
        }else{
            cout << player->getNom() << " n'a pas assez d'argent pour l'acheter" << endl;
        }
    }else{
        cout << player->getNom() << " s'est arrete.e sur " << m_name << " qui appartient a " << m_proprietaire->getNom() << endl;
        if (m_proprietaire->getNbCompagnie() == 1){
        cout << "Le loyer est de " << 400  << " francs" << endl;
        int payement = min(player->getSolde(), 400);
        player->debiter(payement);
        m_proprietaire->crediter(payement);

        cout << player->getNom() << " paie " << payement << " francs a " << m_proprietaire->getNom() << endl;
        }else{
         cout << "le loyer est de " << 1000  << " francs" << endl;  
        int payement = min(player->getSolde(), 1000);
        player->debiter(payement);
        m_proprietaire->crediter(payement);
        cout << player->getNom() << " paie " << payement << " francs a " << m_proprietaire->getNom() << endl;                  
        }

    }
}