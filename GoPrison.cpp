//
// Created by pierr on 28/12/2021.
//

#include "GoPrison.h"

GoPrison::GoPrison(Case *ptsuivante) {
    this->ptsuivante=ptsuivante;
}

void GoPrison::setptsuivante(Case *pt) {
    this->ptsuivante = pt;
}
Case* GoPrison::getptsuivante() {
    return ptsuivante;
}
void GoPrison::jouergoprison() {
//    TODO aller en prison
}
