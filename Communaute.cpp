#include "Communaute.h"

using namespace std;



void jouerCommunaute(){
    
}


string Communaute::getCarteCommunaute(int i){
    return m_carteCommunaute[i];
}

void Communaute::setCarteCommunaute(int i, string name){
    m_carteCommunaute[i] = name;
}