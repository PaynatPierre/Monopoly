#include "Jeu.h"
#include "Case.h"
#include "Propriete.h"
#include "Prison.h"

#include <string>
#include <iostream>

using namespace std;


Jeu :: Jeu ( Joueur ** liste_de_joueurs, Plateau& p,int t = 0, int bonjour = 8) : de1(), de2(), plateau(p){
    nbrdejoueur = bonjour;
    nbelimine = 0;
    tourdejeu = t;
    joueurcourant=0;
    for (int i=0; i<nbrdejoueur ; i++){
        liste[i] = liste_de_joueurs[i];
        liste[i]->getPion()->setPtCase(plateau.getcase(0));
        cout<< liste_de_joueurs[i]->getNom() << endl;
    }
    cout << "Construction du jeu terminee"  << endl;
     
}
//TODO geter et setter de nbelimine

void Jeu::jouer(){
    if(liste[joueurcourant]->getStatus()){
        cout << "c'est a " << liste[joueurcourant]->getNom() << " de jouer" << endl;
        cout << "test1" << endl;
        de1.lancerDe();
        de2.lancerDe();
        cout << liste[joueurcourant]->getNom() << " a obtenu " << de1.getValeur() << " et " << de2.getValeur() << " au lancer de des" <<endl;
        cout << "test2" <<endl;

        if(de1.getValeur() == de2.getValeur()){
            liste[joueurcourant]->setNbDouble(liste[joueurcourant]->getNbDouble() + 1);
        }
        cout << "test3" <<endl;

        if(liste[joueurcourant]->getNbDouble() == 3){
            cout << "test4" <<endl;
            liste[joueurcourant]->setNbDouble(0);
            liste[joueurcourant]->setinprison(true);
            liste[joueurcourant]->settourinprison(0);

            while(liste[joueurcourant]->getPion()->getPtCase()->getName() != "prison"){
                liste[joueurcourant]->getPion()->deplacer();
            }
            cout << liste[joueurcourant]->getNom() << " a obtenue 3 double d'affilé, il va donc directement en prison" <<endl;
            tourdejeu += 1;

            if(joueurcourant == nbrdejoueur - 1){
                joueurcourant = 0;
            }else{
                joueurcourant += 1;
            }

        }else{
            cout << "test5" <<endl;
            if(liste[joueurcourant]->getinprison()){
                cout << "test6" <<endl;
                Case* c = liste[joueurcourant]->getPion()->getPtCase();
                Prison* p = (Prison*)c;
                p->arreterSurPrison(liste[joueurcourant], de1.getValeur(), de2.getValeur());
            }else{
                cout << "test7" <<endl;
                for(int i=0; i<(de1.getValeur()+de2.getValeur()); i++){
                    liste[joueurcourant]->getPion()->deplacer();
                    if(liste[joueurcourant]->getPion()->getPtCase()->getName() == "Case Depart"){
                        liste[joueurcourant]->crediter(20000);
                        cout << liste[joueurcourant]->getNom() << " est passé par la case départ, il/elle reçoit donc 20 000 francs." <<endl;
                    }
                }
                cout << "test8" <<endl;
                if(liste[joueurcourant]->getPion()->getPtCase()->getName() == "prison"){
                    cout << "test9" <<endl;
                    Case* c = liste[joueurcourant]->getPion()->getPtCase();
                    Prison* p = (Prison*)c;
                    p->arreterSurPrison(liste[joueurcourant], de1.getValeur(), de2.getValeur());
                }else{
                    cout << "test10" <<endl;
                    //cout << liste[joueurcourant]->getPion()->getPtCase()->getName() <<endl;

                    liste[joueurcourant]->getPion()->getPtCase()->arreterSur(liste[joueurcourant]);
                    cout << "test11" <<endl;
                }

                if(liste[joueurcourant]->getSolde() == 0){
                    cout << "test16" <<endl;
                    liste[joueurcourant]->perdre();
                    cout << liste[joueurcourant]->getNom() << "n'a plus d'argent il est éliminé" <<endl;
                    tourdejeu += 1;
                    if(joueurcourant == nbrdejoueur - 1){
                        joueurcourant = 0;
                    }else{
                        joueurcourant += 1;
                    }
                }else{
                    cout << "test12" <<endl;
                    if(de1.getValeur() != de2.getValeur()){
                        cout << "test13" <<endl;
                        if(joueurcourant == nbrdejoueur - 1){
                            cout << "test14" <<endl;
                            joueurcourant = 0;
                        }else{
                            cout << "test15" <<endl;
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
        cout << "test17" <<endl;
        if(joueurcourant == nbrdejoueur - 1){
            cout << "test18" <<endl;
            joueurcourant = 0;
        }else{
            cout << "test19" <<endl;
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

Joueur* Jeu::getjoueur(int i){
    return liste[i];
}
void Jeu::setjoueur(Joueur* j, int i){
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
        cout<< " lancement d'un tout avec joueurcourant = " << joueurcourant << endl;
        jouer();
    }
}