#include "Chance.h"
#include "ParckGratuit.h"
#include "Jeu.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>


using std::this_thread::sleep_for;
using namespace std::chrono_literals;
using namespace std;

Chance::Chance(string nom, Case* ptsuivante) : Case(nom, ptsuivante){
}

void Chance::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arrete.e sur " << m_name << endl;
    cout << player->getNom() << " a tire la carte :  " <<  endl;
    sleep_for(300ms);
    srand((unsigned int)time(0));
    int i = rand() % 10;
    ifstream liste_carte_chance("Carte_Chance/Chance" + to_string(i) + ".txt");
    if(liste_carte_chance){
        string descr;
        getline(liste_carte_chance, descr);
        cout << descr << endl;
        string methode;
        getline(liste_carte_chance, methode);
        string info;
        getline(liste_carte_chance, info);

        if(methode == "p"){
            int somme_due;
            somme_due = stoi(info);
            int paiement = min(player->getSolde(), somme_due);
            cout << player->getNom() << " perd F. " << paiement << endl;
            (*player)-=paiement;

            Case * c = this;
            while(c->getName() != "parck_gratuit"){
                c = c->getSuivante();}

            ParckGratuit* p = (ParckGratuit*)c;
            p->addcagnotte(paiement);
            }
            
        else if(methode == "g"){
            int somme_percue;
            somme_percue = stoi(info);
            cout << player->getNom() << " gagne F. " << somme_percue << endl;            
            (*player)+=somme_percue;}

        else if(methode == "d"){
            while(player->getPion()->getPtCase()->getName() != info){
                (*player->getPion())++;
                if(player->getPion()->getPtCase()->getName() == "Case Depart"){
                    (*player)+=20000;
                    cout << player->getNom() << " est passe par la case depart et gagne donc F 20.000 " << endl;   
                }
            }
            cout << player->getNom() << " est desormais sur la case " << info << endl;}

        else if(methode == "r"){
            int deplacement(39-stoi(info));
            for(int i = 0; i < deplacement; i++){
                (*player->getPion())++;}
            cout << player->getNom() << " est desormais sur la case " << player->getPion()->getPtCase()->getName() << endl;
            player->getPion()->getPtCase()->arreterSur(player);}

        else if(methode == "x"){
            player->setinprison(true);
            player->settourinprison(0);
            player->setNbDouble(0);
            while(player->getPion()->getPtCase()->getName() != info){
                (*player->getPion())++;}
            cout <<   player->getNom() << " a donc ete emmene.e en prison, il/elle ne passe pas par la case depart et ne recoit pas 20 000 francs"<< endl;
            }
    }

}

string Chance::getCarteChance(int i){
    return m_carteChance[i];
}

void Chance::setCarteChance(int i, string name){
    m_carteChance[i] = name;
}




