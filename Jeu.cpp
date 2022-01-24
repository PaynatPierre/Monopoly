#include "Jeu.h"
#include "Case.h"
#include "Propriete.h"
#include "Prison.h"
#include "Joueur_Pion.h"

#include <string>
#include <iostream>

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
        de1.lancerDe();
        de2.lancerDe();
        cout << liste[joueurcourant].getNom() << " a obtenu " << de1.getValeur() << " et " << de2.getValeur() << " au lancer de des" <<endl;

        if(de1.getValeur() == de2.getValeur()){
            liste[joueurcourant].setNbDouble(liste[joueurcourant].getNbDouble() + 1);
        }

        if(liste[joueurcourant].getNbDouble() == 3){
            liste[joueurcourant].setNbDouble(0);
            liste[joueurcourant].setinprison(true);
            liste[joueurcourant].settourinprison(0);

            while(liste[joueurcourant].getPion()->getPtCase()->getName() != "prison"){
                liste[joueurcourant].getPion()->deplacer();
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
                    liste[joueurcourant].getPion()->deplacer();
                    if(liste[joueurcourant].getPion()->getPtCase()->getName() == "Case Depart"){
                        liste[joueurcourant].crediter(20000);
                        cout << liste[joueurcourant].getNom() << " est passe par la case depart, il/elle recoit donc 20 000 francs" <<endl;
                    }
                }
                if(liste[joueurcourant].getPion()->getPtCase()->getName() == "prison"){
                    Case* c = liste[joueurcourant].getPion()->getPtCase();
                    Prison* p = (Prison*)c;
                    p->arreterSurPrison(&liste[joueurcourant], de1.getValeur(), de2.getValeur());
                }else{
                    liste[joueurcourant].displayInfo();
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