#include <iostream>
#include "GoPrison.h"

GoPrison::GoPrison(Case *Ptsuivante) {
    ptsuivante=Ptsuivante;
}

void GoPrison::setptsuivante(Case *pt) {
    ptsuivante = pt;
}
Case* GoPrison::getptsuivante() {
    return ptsuivante;
}
void GoPrison::jouergoprison() {
//    TODO aller en prison
}


void GoPrison::arreterSur(){
    
}