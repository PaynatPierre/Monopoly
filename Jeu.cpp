//
// Created by pierr on 15/12/2021.
//

#include "Jeu.h"
#include "Plateau.h"
#include "Joueur_Pion.h"
#include "De_Gobelet.h"
#include "Prison.h"
#include <iostream>
using namespace std;


Jeu :: Jeu ( Joueur ** liste_de_joueurs, int t = 0, int bonjour = 8) : de1(), de2(), plateau(){
    nbrdejoueur = bonjour;
    nbelimine = 0;
    tourdejeu = t;
    joueurcourant=0;
    plateau.creercase();
    for (int i=0; i<nbrdejoueur ; i++){
        liste[i] = liste_de_joueurs[i];
        liste[i]->getPion()->setPtCase(plateau.getcase(0));
    }   
     
}
//TODO geter et setter de nbelimine

void Jeu::jouer(){
    if(this->liste[this->joueurcourant]->getStatus()){
        cout << "c'est à " << this->liste[this->joueurcourant]->getNom() << " de jouer" <<endl;
        cout << "test1" <<endl;
        de1.lancerDe();
        de2.lancerDe();
        cout << this->liste[this->joueurcourant]->getNom() << " a obtenu " << de1.getValeur() << " et " << de2.getValeur() << " au lancer de dés" <<endl;
        cout << "test2" <<endl;

        if(de1.getValeur() == de2.getValeur()){
            this->liste[this->joueurcourant]->setNbDouble(this->liste[this->joueurcourant]->getNbDouble() + 1);
        }
        cout << "test3" <<endl;

        if(this->liste[this->joueurcourant]->getNbDouble() == 3){
            cout << "test4" <<endl;
            this->liste[this->joueurcourant]->setNbDouble(0);
            this->liste[this->joueurcourant]->setinprison(true);
            this->liste[this->joueurcourant]->settourinprison(0);

            while(this->liste[this->joueurcourant]->getPion()->getPtCase()->getName() != "prison"){
                this->liste[this->joueurcourant]->getPion()->deplacer();
            }
            cout << this->liste[this->joueurcourant]->getNom() << " a obtenue 3 double d'affilé, il va donc directement en prison" <<endl;
            tourdejeu += 1;

            if(this->joueurcourant == nbrdejoueur - 1){
                joueurcourant = 0;
            }else{
                joueurcourant += 1;
            }

        }else{
            cout << "test5" <<endl;
            if(this->liste[this->joueurcourant]->getinprison()){
                cout << "test6" <<endl;
                Case* c = this->liste[this->joueurcourant]->getPion()->getPtCase();
                Prison* p = (Prison*)c;
                p->arreterSurPrison(this->liste[this->joueurcourant], de1.getValeur(), de2.getValeur());
            }else{
                cout << "test7" <<endl;
                for(int i=0; i<(de1.getValeur()+de2.getValeur()); i++){
                    this->liste[this->joueurcourant]->getPion()->deplacer();
                    if(this->liste[this->joueurcourant]->getPion()->getPtCase()->getName() == "Case Depart"){
                        this->liste[this->joueurcourant]->crediter(20000);
                        cout << this->liste[this->joueurcourant]->getNom() << " est passé par la case départ, il/elle reçoit donc 20 000 francs." <<endl;
                    }
                }
                cout << "test8" <<endl;
                if(this->liste[this->joueurcourant]->getPion()->getPtCase()->getName() == "prison"){
                    cout << "test9" <<endl;
                    Case* c = this->liste[this->joueurcourant]->getPion()->getPtCase();
                    Prison* p = (Prison*)c;
                    p->arreterSurPrison(this->liste[this->joueurcourant], de1.getValeur(), de2.getValeur());
                }else{
                    cout << "test10" <<endl;
                    cout << this->liste[this->joueurcourant]->getPion()->getPtCase()->getName() <<endl;
                    this->liste[this->joueurcourant]->getPion()->getPtCase()->arreterSur(this->liste[this->joueurcourant]);
                }

                if(this->liste[this->joueurcourant]->getSolde() == 0){
                    this->liste[this->joueurcourant]->perdre();
                    cout << this->liste[this->joueurcourant]->getNom() << "n'a plus d'argent il est éliminé" <<endl;
                    tourdejeu += 1;
                    if(this->joueurcourant == nbrdejoueur - 1){
                        joueurcourant = 0;
                    }else{
                        joueurcourant += 1;
                    }
                }else{
                    if(de1.getValeur() != de2.getValeur()){
                        if(this->joueurcourant == nbrdejoueur - 1){
                            joueurcourant = 0;
                        }else{
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
        if(this->joueurcourant == nbrdejoueur - 1){
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
    return this->nbrdejoueur;
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
    while(nbelimine < nbrdejoueur-1){
        this->jouer();
    }
}