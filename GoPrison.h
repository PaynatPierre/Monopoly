//
// Created by pierr on 28/12/2021.
//

#ifndef CODEPROJET5_GOPRISON_H
#define CODEPROJET5_GOPRISON_H
#include "Case.h"

class GoPrison : public Case{
public:
    Goprison(Case* ptsuivante);
    void setptsuivante(Case* pt);
    Case* getptsuivante();
    void jouergoprison();
private:
    Case* ptsuivante;
};


#endif //CODEPROJET5_GOPRISON_H
