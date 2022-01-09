//
// Created by pierr on 15/12/2021.
//

#include "Plateau.h"
#include "Case.h"
#include "Depart.h"
#include "Communaute.h"
#include "ParckGratuit.h"
#include "GoPrison.h"
#include "Prison.h"
#include "Terrain.h"
#include "Impot.h"
#include <iostream>
using namespace std;

Plateau::Plateau() {

}
Case* Plateau::getcase(int i) {
    return this->cases[i];
}
void Plateau::setcase(Case* c, int i) {
    this->cases[i] = c;
}
void Plateau::creercase() {

    Depart dp(20000, NULL);
    this->setcase(&dp,0);

    Terrain t1("bleu fonce", "rue de la paix", &dp, 40000, {5000,20000,60000,140000,170000,200000}, 20000);
    this->setcase(&t1,39);

    Impot i1("taxe de luxe",10000, &t1);
    this->setcase(&i1,38);

    Terrain t2("bleu foncé", "avenue des champs élysées", &i1, 35000, {3500,17500,50000,110000,130000,150000}, {20000,20000});
    this->setcase(&t2,37);

    Chance c1(&t2);
    this->setcase(&c1,36);

    Gare g1 = new Gare("gare saint lazare", &c1, 20000, {2500,5000,10000,20000});
    this->setcase(&g1,35);

    Terrain t3("vert", "boulevard des capucines", &g1, 32000, {2800,15000,45000,100000,120000,140000}, {20000,20000});
    this->setcase(&t3,34);

    Communaute co1(&t3);
    this->setcase(&co1, 33);

    Terrain t4("vert", "avenue foch", &co1, 30000, {2600,13000,39000,90000,110000,127500}, {20000,20000});
    this->setcase(&t4,32);

    Terrain t5("vert", "avenue de breuteuil", &t4, 30000, {2600,13000,39000,90000,110000,127500}, {20000,20000});
    this->setcase(&t5,31);

    GoPrison gp(&t5);
    this->setcase(gp,30);

    Terrain t6("jaune", "rue lafayette", &gp, 28000, {2400,12000,36000,85000,102000,120000}, {15000,15000});
    this->setcase(&t6,29);

    Companie comp1("companie des eaux",&t6);
    this->setcase(&comp1,28);

    Terrain t7("jaune", "place de la bourse", &comp1, 26000, {2200,11000,33000,80000,97500,115000}, {15000,15000});
    this->setcase(&t7,27);

   int loyer_t8[6] = {2200,11000,33000,80000,97500,115000};
    Terrain t8("jaune", "faubourg saint-honoré", &t7, 26000, loyer_t8, 15000);
    this->setcase(&t8,26);

    int loyer_g2[6] = {2500,5000,10000,20000, 0, 0};
    Gare g2("gare du nord", &t8, 20000, loyer_g2);
    this->setcase(&g2,25);

    int loyer_t9[6] = {2000,10000,30000,75000,92500,110000};
    Terrain t9("rouge", "avenue henri-martin", &g2, 24000, loyer_t9, 15000);
    this->setcase(&t9,24);

    int loyer_t10[6] = {1800,9000,25000,70000,87500,105000};
    Terrain t10("rouge", "boulevard malesgerbes", &t9, 22000, loyer_t10, 15000);
    this->setcase(&t10,23);

    chance c2(&t10);
    this->setcase(&c2,22);

    int loyer_t11[6] = {1800,9000,25000,70000,87500,105000};
    Terrain t11("rouge", "avenue matignon", &c2, 22000, loyer_t11, 15000);
    this->setcase(&t11,21)

    ParckGratuit pg(&t11, 0);
    this->setcase(&pg,20);

    int loyer_t12[6] = {1600,8000,22000,60000,80000,100000};
    Terrain t12("orange", "place pigalle", &pg, 20000, loyer_t12, 10000);
    this->setcase(&t12,19);

    int loyer_t13[6] = {1400,7000,20000,55000,75000,95000};
    Terrain t13("orange", "boulevard saint-michel", &t12, 18000, loyer_t12, 10000);
    this->setcase(&t13,18);

    Communaute co2(&t13);
    this->setcase(&co2, 17);


    int loyer_t14[6] = {1400,7000,20000,55000,75000,95000};
    Terrain t14("orange", "avenue mozart", &co2, 18000, loyer_t14, 10000);
    this->setcase(&t14,16);

    int loyer_t14[6] = {2500,5000,10000,20000, 0, 0};
    Gare g3("gare de lyon", &t14, 20000, loyer_t14);
    this->setcase(&g3,15);

    int loyer_t15[6] = {1200,6000,18000,50000,70000,90000};
    Terrain t15("violet", "rue de paradis", &g3, 16000, loyer_t15, 10000);
    this->setcase(&t15,14);

    int loyer_t16[6] = {1000,5000,15000,45000,62000,75000};
    Terrain t16("violet", "avenue de neuilly", &t15, 14000, loyer_t16, 10000);
    this->setcase(&t16,13);

    Companie comp2("compagnie d'electricité", &t16);
    this->setcase(&comp2,12);

    int loyer_t17[6] = {1000,5000,15000,45000,62000,75000};
    Terrain t17("violet", "boulevard de la villette", &comp2, 14000, loyer_t17, 10000);
    this->setcase(&t17,11);

    int loyer_t18[6] = {800,4000,10000,30000,45000,60000};
    Terrain t18("bleu clair", "avenue de la république", &p1, 12000, loyer_t18, 5000);
    this->setcase(&t18,9);

    int loyer_t19[6] = {600,3000,9000,27000,40000,55000};
    Terrain t19("bleu clair", "rue de courcelles", &t18, 10000, loyer_t19, 5000);
    this->setcase(&t19,8);

    chance c3(&t19);
    this->setcase(&c3,7);

    int loyer_t20[6] = {600,3000,9000,27000,40000,55000};
    Terrain t20("bleu clair", "rue de vaugirard", &c3, 10000, loyer_t20, 5000);
    this->setcase(&t20,6);

    int loyer_g4[6] = {2500,5000,10000,20000,0,0};
    Gare g4("gare montparnasse", &t20, 20000, loyer_g4);
    this->setcase(&g4,5);

    Impot i2("impot sur le revenu",20000, &g4);
    this->setcase(&i2,4);

    int loyer_t21[6] = {400,2000,6000,18000,32000,45000};
    Terrain t21("maron", "rue lecourbe", &i2, 6000, loyer_t21, 5000);
    this->setcase(&t21,3);

    Communaute co3(&t21);
    this->setcase(&co3, 2);

    int loyer_t21[6] = {200,1000,3000,9000,16000,25000};
    Terrain t22("maron", "boulevard de belleville", &co3, 6000, loyer_t21, 5000);
    this->setcase(&t21,1);

    dp.setSuivante(&t22);
}
