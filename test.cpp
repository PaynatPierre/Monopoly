#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool is_in(T elmt, T *tab){
    int arrSize = sizeof(tab)/sizeof(tab[0]);
    for (int i = 0; i< arrSize; i++){
        if (elmt == tab[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int tab[3] = {1,2,3};
    int elmt;
    cout << "Veuillez choisir un nombre entier: " << endl;
    cin >> elmt;
    if (is_in(elmt, tab)){
        cout << "Votre element est bien dans notre liste secrete !" << endl;
    }
    else {
        cout << "Votre element n'est pas dans notre liste" << endl;
    }
    return 0;
}