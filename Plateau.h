//
// Created by pierr on 15/12/2021.
//

#ifndef CODEPROJET4_PLATEAU_H
#define CODEPROJET4_PLATEAU_H


class Plateau {
private:
    Case cases[40];
protected:
public:
    Plateau();
    Case getcase(int i);
    void setcase(Case c, int i);
    void creercase();
};


#endif //CODEPROJET4_PLATEAU_H
