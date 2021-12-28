//
// Created by pierr on 15/12/2021.
//

#include "Plateau.h"
#include "Case.h"
#include "Depart.h"
#include "Communaute.h"

Plateau::Plateau() {

}
Case* Plateau::getcase(int i) {
    return this->cases[i];
}
void Plateau::setcase(Case* c, int i) {
    this->cases[i] = c;
}
void Plateau::creercase() {
    //TODO creer toutes les cases

    Depart dp(20000, NULL);
    this->setcase(&dp,0);

    Terrain t1("bleu foncé", "rue de la paix", &dp, 40000, {5000,20000,60000,140000,170000,200000}, {20000,20000});
    this->setcase(&t1,39)

    Impot i1("taxe de luxe",10000, &t1);
    this->setcase(&i1,38);

    Terrain t2("bleu foncé", "avenue des champs élysées", &i1, 35000, {3500,17500,50000,110000,130000,150000}, {20000,20000});
    this->setcase(&t2,37)

    Chance c1(&t2);
    this->setcase(&c1,36)

    Gare g1 = new Gare("gare saint lazare", &c1, 20000, {2500,5000,10000,20000});
    this->setcase(&g1,35)

    Terrain t3("vert", "boulevard des capucines", &g1, 32000, {2800,15000,45000,100000,120000,140000}, {20000,20000});
    this->setcase(&t3,34)

    Communaute co1(&t3);
    this->setcase(&c01, 33)

    Terrain t4("vert", "avenue foch", &co1, 30000, {2600,13000,39000,90000,110000,127500}, {20000,20000});
    this->setcase(&t4,32)

    Terrain t5("vert", "avenue de breuteuil", &t4, 30000, {2600,13000,39000,90000,110000,127500}, {20000,20000});
    this->setcase(&t5,31)

    GoPrison gp(&t5);
    this->setcase(gp,30)


}
