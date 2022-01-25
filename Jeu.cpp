#include "Jeu.h"
#include "Case.h"
#include "Propriete.h"
#include "Prison.h"
#include "Joueur_Pion.h"
#include "Terrain.h"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using std::copy;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

using namespace std;


Jeu :: Jeu (Plateau& p,int t = 0) : de1(), de2(), plateau(p){
    nbrdejoueur = 0;
    nbelimine = 0;
    tourdejeu = t;
    joueurcourant=0;
    cout << "Construction du jeu terminee"  << endl;
     
}

void Jeu::create_joueur(std::string &nom, std::string &nom_pion){
    
    liste[nbrdejoueur] = Joueur(nom,nom_pion, plateau.getcase(0), NULL,0,0,0,150000,0,false,0, true);
    nbrdejoueur += 1;
}

void Jeu::jouer(){
    if(liste[joueurcourant].getStatus()){
        cout << "C'est a " << liste[joueurcourant].getNom() << " de jouer" << endl;
        cout << "\nLancement des des ";
        sleep_for(300ms);
        cout << ".";
        de1.lancerDe();
        sleep_for(300ms);
        cout << ".";
        de2.lancerDe();
        cout << "." << endl;
        sleep_for(300ms);
        cout << liste[joueurcourant].getNom() << " a obtenu " << de1.getValeur() << " et " << de2.getValeur() << " au lancer de des" <<endl;

        if(de1.getValeur() == de2.getValeur()){
            liste[joueurcourant].setNbDouble(liste[joueurcourant].getNbDouble() + 1);
        }

        if(liste[joueurcourant].getNbDouble() == 3){
            liste[joueurcourant].setNbDouble(0);
            liste[joueurcourant].setinprison(true);
            liste[joueurcourant].settourinprison(0);

            while(liste[joueurcourant].getPion()->getPtCase()->getName() != "prison"){
                (*liste[joueurcourant].getPion())++;
            }
            cout << liste[joueurcourant].getNom() << " a obtenu 3 doubles d'affile, il va donc directement en prison" <<endl;
            tourdejeu += 1;

            if(joueurcourant == nbrdejoueur - 1){
                joueurcourant = 0;
            }else{
                joueurcourant += 1;
            }

        }else{
            if(liste[joueurcourant].getinprison()){
                Case* c = liste[joueurcourant].getPion()->getPtCase();
                Prison* p = (Prison*)c;
                p->arreterSurPrison(&liste[joueurcourant], de1.getValeur(), de2.getValeur());

                if(de1.getValeur() != de2.getValeur()){
                        if(joueurcourant == nbrdejoueur - 1){
                            liste[joueurcourant].setNbDouble(0);
                            joueurcourant = 0;
                        }else{
                            liste[joueurcourant].setNbDouble(0);
                            joueurcourant += 1;
                        }
                        tourdejeu +=1;
                }else{
                    tourdejeu += 1;
                }
            }else{
                for(int i=0; i<(de1.getValeur()+de2.getValeur()); i++){
                    (*liste[joueurcourant].getPion())++;
                    if(liste[joueurcourant].getPion()->getPtCase()->getName() == "Case Depart"){
                        liste[joueurcourant]+=20000;
                        cout << liste[joueurcourant].getNom() << " est passe par la case depart, il/elle recoit donc 20 000 francs" <<endl;
                    }
                }
                if(liste[joueurcourant].getPion()->getPtCase()->getName() == "prison"){
                    Case* c = liste[joueurcourant].getPion()->getPtCase();
                    Prison* p = (Prison*)c;
                    p->arreterSurPrison(&liste[joueurcourant], de1.getValeur(), de2.getValeur());
                }else{
                    string info = "Oui";
                    cout << "Voulez-vous voir vos informations ? (Ecrire 'Oui')" << endl;
                    cin >> info;
                    if (info == "Oui"){
                        liste[joueurcourant].displayInfo();
                    }
                    else {
                        cout << "On continue, donc !" << endl;
                    }
                    liste[joueurcourant].getPion()->getPtCase()->arreterSur(&liste[joueurcourant]);
                }

                if(liste[joueurcourant].getSolde() == 0){
                    liste[joueurcourant].perdre();
                    cout << liste[joueurcourant].getNom() << " n'a plus d'argent, il/elle est elimine.e" <<endl;
                    tourdejeu += 1;
                    nbelimine += 1;

                    if(joueurcourant == nbrdejoueur - 1){
                        joueurcourant = 0;
                    }else{
                        joueurcourant += 1;
                    }
                }else{
                    jouer_maison();

                    if(de1.getValeur() != de2.getValeur() || liste[joueurcourant].getinprison()){
                        if(joueurcourant == nbrdejoueur - 1){
                            liste[joueurcourant].setNbDouble(0);
                            joueurcourant = 0;
                        }else{
                            liste[joueurcourant].setNbDouble(0);
                            joueurcourant += 1;
                        }
                        tourdejeu +=1;
                    }else{
                        tourdejeu += 1;
                    }
                }


            }
        }

    }else{
        if(joueurcourant == nbrdejoueur - 1){
            joueurcourant = 0;
        }else{
            joueurcourant += 1;
        }

    }
}

void Jeu::jouer_maison(){
            int terrain_id[40];
            int nbterrain = 0;
            for(int i=0; i < liste[joueurcourant].getNbPropriete(); i++){
                if(liste[joueurcourant].getListe_acquisitions()[i]->getName() != "gare_saint_lazare" && liste[joueurcourant].getListe_acquisitions()[i]->getName() != "Compagnie_des_eaux" && liste[joueurcourant].getListe_acquisitions()[i]->getName() != "gare_du_nord" && liste[joueurcourant].getListe_acquisitions()[i]->getName() != "gare_de_lyon" && liste[joueurcourant].getListe_acquisitions()[i]->getName() != "compagnie_d_electricite" && liste[joueurcourant].getListe_acquisitions()[i]->getName() != "gare_montparnasse"){
                    if(((Terrain*)(liste[joueurcourant].getListe_acquisitions()[i]))->getprixm_h() < liste[joueurcourant].getSolde() && ((Terrain*)(liste[joueurcourant].getListe_acquisitions()[i]))->getnbrmaison()<5){
                        terrain_id[nbterrain] = i;
                        nbterrain += 1;
                    }
                }
            }

            if(nbterrain == 0){
                cout<< liste[joueurcourant].getNom() << " ne peut pas mettre de maison" <<endl;
            }else{
                cout<< "vous pouvez mettre de maisons sur : ";
                for(int i=0; i<nbterrain; i++){
                    cout<<((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[i]]))->getName() << " ,";
                }
                cout<<" "<<endl;

                int reponse = 0;
                bool acceptable = false;

                while(acceptable == false){
                    cout<<"si vous souhaitez mettre des maisons sur une de ces proprietes entrez son indice, dans le cas contraire entrez 0"<<endl;
                    cin>>reponse;

                    if(reponse==0 || (reponse>0 && reponse<=nbterrain)){
                        acceptable = true;
                    }
                    else {
                        string error = "Error not a int given or out of bound"; 
                        throw error;
                    }
                    
                }

                if(reponse == 0){
                    cout<< liste[joueurcourant].getNom() << " ne souhaite pas mettre de maison"<<endl;
                }else{
                    int indice_ville = reponse -1 ;

                    int reponse2;
                    bool acceptable2 = false;
                    while(acceptable2 != true){
                        cout<< "combien de maison souhaitez vous acheter"<<endl;
                        cin>>reponse2;

                        if(reponse2 > 5 - ((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getnbrmaison()){
                            cout<<"une ville ne peut acceuillir que 5 maison"<<endl;
                        }else if(reponse2<1){
                            cout<<"veuillez entrer un nombre superieur ou egal a 1"<< endl;
                        }else if(reponse2*((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getprixm_h() > liste[joueurcourant].getSolde()){
                            cout<<"vous n avez pas assez d argent pour acheter autant de maison"<<endl;
                        }else if(reponse2 <= 5){
                            acceptable2 = true;
                            //cout<<((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getprixm_h() << " test1" <<endl;
                            int payement = reponse2*((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getprixm_h();
                            //cout<< payement << " test2" <<endl;

                            liste[joueurcourant]-=payement;
                            ((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->setnbrmaison(reponse2 + ((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getnbrmaison());
                            cout<<liste[joueurcourant].getNom() << " a depense " << payement << " francs pour ajouter " << reponse2 << " maison sur " << ((Terrain*)(liste[joueurcourant].getListe_acquisitions()[terrain_id[indice_ville]]))->getName()<<endl;
                        }
                        else {
                            string error = "Error not a int given"; 
                            throw error;
                        }
                    }
                }
                

    
            }
}

bool Jeu::compare(string s1, string s2){
    if(s1.size() == s2.size()){
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

int Jeu::gettourdejeu(){
    return tourdejeu;
}
void Jeu::settourdejeu(int i){
    tourdejeu = i;
}
void Jeu::toursuivant(){
    tourdejeu = tourdejeu +1;
}

int Jeu::getnbrjoueur(){
    return nbrdejoueur;
}
void Jeu::setnbrjoueur(int i){
   nbrdejoueur = i;
}

Plateau Jeu::getplateau(){
    return plateau;
}
void Jeu::setplateau(Plateau pl){
    plateau = pl;
}

Joueur Jeu::getjoueur(int i){
    return liste[i];
}
void Jeu::setjoueur(Joueur j, int i){
    liste[i] = j;
}

De Jeu :: getde1(){
    return de1;
}

De Jeu :: getde2(){
    return de2;
}

void Jeu::schedule(){
    cout << "Lancement du jeu" << endl;
    while(nbelimine < nbrdejoueur-1){
        cout<< "=============================================================="<< endl;
        cout<< "                    Tour numero " << tourdejeu + 1 << "                       " <<endl;
        cout<< "==============================================================" << endl;
        jouer();
    }

    Joueur* player;
    for(int i =0; i<nbrdejoueur; i++){
        if(liste[i].getStatus()){
            player = &liste[i];
        }
    }


    cout<< "  "<<endl;
    cout<< "  "<<endl;
    cout<< "************************************************************************" <<endl;
    cout<< "                    La partie est finie "<<endl;
    cout<< "************************************************************************" <<endl;
    cout<< "  "<<endl;
    cout<< player->getNom() << " a gagne la partie. Felicitations !!!!!"<<endl;

}