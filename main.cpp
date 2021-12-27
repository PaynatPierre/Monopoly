#include "Jeu.h"
#include <iostream>
#include "Joueur_Pion.h"
#include "Joueur_Pion.cpp"
#include "Propriété.h"
using namespace std;

void startgame();

int main() {
    startgame();
    return 0;
}
//  TODO print le list de pion disponible
bool goodpion(string pion, string tab[], int nbr_pion){
    string goodpion[8] = {"cheval", "chapeau", "tour eiffel", "tour de pise", "colisé", "sagrada famillia", "clef", "voiture"};

//  verification que le pion choisi soit valide
    for(int i = 0; i<8; i++){
        if(pion == goodpion[i]){
//          verification que le pion ne soit pas deja utilisé
            for(int j = 0; i<nbr_pion; i++){
                if(pion == tab[j]){
                    cout << "désolé ce pion a deja été choisi par un autre joueur\n\n";
                    return false;
                }
            }
            return true;
        }
    }
    cout << "désolé ce pion n'existe pas, les pion possible sont : cheval, chapeau, tour eiffel, tour de pise, sagrada famillia, clef et voiture\n\n";
    return false;
}

void startgame(){
//  variable utile pour construire l'objet jeu
    int nbr_player;
    string player[8];
    string pion[8];

//  message de bienvenue
    cout << "Bienvenue dans le jeu Monopoly\n";

//  choix du nombre de joueur
//  TODO levé d'erreur si l'utilisateur entre un string
    cout << "combien y aura-t-il de joueur :\n";
    cin >> nbr_player;
    while(nbr_player > 8){
        cout << "Impossible, le nombre maximum de joueur est de 8.\n";
        cout << "combien y aura-t-il de joueur :\n";
        cin >> nbr_player;
    }
    cout << "nous jouerons donc une partie avec " << nbr_player << " joueurs\n\n";

//  choix du nom de chaque joueur et du pion qui lui sera associé
    for(int i = 0; i < nbr_player; i++){
        cout << "qui sera le joueur " << i << " :\n";
        cin >> player[i];
        cout << "Bonjour " << player[i] << ". Avec quel pion souhaites tu jouer ?\n";
        string trypion;
        cin >> trypion;
        while(not(goodpion(trypion, pion, i))){
            cout << "Avec quel pion souhaites tu jouer " << player[i] << " ?\n";
            cin >> trypion;
        }
        pion[i] = trypion;
    }

//    appel du constructeur de jeu
    Joueur *liste[nbr_player];
    for(int i = 0; i < nbr_player; i++){
        const Propriete* p[40];
        const Pion(NULL,NULL);
        Joueur j = new Joueur(player[i], 1500,true, pion[i],0, p,0);
        liste[i]= &j;
    }

    Jeu Jeu(nbr_player, liste);
}

