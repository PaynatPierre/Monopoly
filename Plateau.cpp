//
// Created by pierr on 15/12/2021.
//

#include "Plateau.h"

Plateau::Plateau() {

}
Case Plateau::getcase(int i) {
    return this->cases[i];
}
void Plateau::setcase(int i, Case c) {
    this->cases[i] = c;
}
void Plateau::creercase() {
    //TODO creer toutes les cases
}
