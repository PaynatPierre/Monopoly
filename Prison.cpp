#include "Prison.h"
#include "Jeu.h"
#include <iostream>
using namespace std;

Prison::Prison(Case *ptsuivante) : Case("prison", ptsuivante){
}

void Prison::arreterSurPrison(Joueur* player, int de1, int de2){
    
    if(player->getinprison()){
        if(player->gettourinprison() < 3){
            if(de1 == de2){
                player->setinprison(false);
                cout <<  "Vous sortez de prison au prochain tour " << endl;}
            else{
                player->settourinprison(player->gettourinprison()+1);}
                cout <<  "Vous etes actuellement a " << player->gettourinprison()  << " tours en prison" <<endl;
        }else{
            player->setinprison(false); 
            cout <<  "Vous sortez de prison au prochain tour " << endl;           
        }
    }else{
    cout <<  "Vous etes en simple visite " << endl;}
}

void Prison::arreterSur(Joueur* player){

}