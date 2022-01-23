#include "Prison.h"

#include <string>
#include <iostream>
using namespace std;

Prison::Prison(Case *ptsuivante) : Case("prison", ptsuivante){
}

void Prison::arreterSurPrison(Joueur* player, int de1, int de2){
    //cout << "Hello je suis une case Prison" << endl;
    if(player->getinprison()){
        if(player->gettourinprison() < 2){
            if(de1 == de2){
                player->setinprison(false);
                player->settourinprison(0);
                cout <<  "Vous sortez de prison au prochain tour " << endl;}
            else{
                player->settourinprison(player->gettourinprison()+1);}
                cout <<  "Vous etes actuellement a " << player->gettourinprison()  << " tours en prison" <<endl;
        }else{
            player->setinprison(false); 
            player->settourinprison(0);
            cout <<  "Vous sortez de prison au prochain tour " << endl;           
        }
    }else{
    cout <<  "Vous etes en simple visite  de la prison" << endl;}
}

void Prison::arreterSur(Joueur* player){
    cout << "Hello je suis une case Prison" << endl;
}