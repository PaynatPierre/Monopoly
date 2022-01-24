#include "Chance.h"
#include "ParckGratuit.h"
#include "Jeu.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Chance::Chance(string nom, Case* ptsuivante) : Case(nom, ptsuivante){
}

void Chance::arreterSur(Joueur* player){
    cout << player->getNom() << " s'est arrete.e sur " << m_name << endl;
    int i = 9;
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
            player->debiter(paiement);

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
            player->crediter(somme_percue);}

        else if(methode == "d"){
            while(player->getPion()->getPtCase()->getName() != info){
                player->getPion()->deplacer();
                if(player->getPion()->getPtCase()->getName() == "Case Depart"){
                    player->crediter(20000);
                    cout << player->getNom() << " est passe par la case depart et gagne donc F 20.000 " << endl;   
                }
            }
            cout << player->getNom() << " est desormais sur la case " << info << endl;}

        else if(methode == "r"){
            int deplacement(40-stoi(info));
            for(int i = 0; i < deplacement; i++){
                player->getPion()->deplacer();}
            cout << player->getNom() << " est desormais sur la case " << player->getPion()->getPtCase()->getName() << endl;
            player->getPion()->getPtCase()->arreterSur(player);}

        else if(methode == "p"){
            while(player->getPion()->getPtCase()->getName() != info){
                player->getPion()->deplacer();
                player->getPion()->getPtCase()->arreterSur(player);}
            }
    }

}

string Chance::getCarteChance(int i){
    return m_carteChance[i];
}

void Chance::setCarteChance(int i, string name){
    m_carteChance[i] = name;
}




