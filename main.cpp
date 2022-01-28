#include "Jeu.h"
#include "Communaute.h"
#include "ParckGratuit.h"
#include "GoPrison.h"
#include "Prison.h"
#include "Terrain.h"
#include "Impot.h"
#include "Gare.h"
#include "Compagnie.h"
#include "Chance.h"
#include "Depart.h"
#include "Plateau.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using std::copy;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;
using namespace std;

template <typename T>
bool is_in(T elmt, T *tab, int taille = 0){
    for (int i = 0; i< taille; i++){
        if (elmt == tab[i]){
            return true;
        }
    }
    return false;
}

int main() {

    cout << "Creation du plateau..." << endl;
    Plateau plateau;
    Depart dp(20000, NULL);
    plateau.setcase(&dp,0);

    int loyer_t1[6]= {5000,20000,60000,140000,170000,200000};
    Terrain t1("bleu fonce", "rue_de_la_paix", plateau.getcase(0), 40000, loyer_t1, 20000);
    plateau.setcase(&t1,39);

    Impot i1("taxe_de_luxe",&t1, 10000);
    plateau.setcase(&i1,38);

    int loyer_t2[6]= {3500,17500,50000,110000,130000,150000};
    Terrain t2("bleu foncé", "avenue_des_champs_elysees", &i1, 35000, loyer_t2, 20000);
    plateau.setcase(&t2,37);

    Chance c1("chance_1", &t2);
    plateau.setcase(&c1,36);

    int loyer_g1[6]= {2500,5000,10000,20000,0,0};
    Gare g1 ("gare_saint_lazare", &c1, 20000, loyer_g1);
    plateau.setcase(&g1,35);

    int loyer_t3[6]= {2800,15000,45000,100000,120000,140000};
    Terrain t3("vert", "boulevard_des_capucines", &g1, 32000,loyer_t3, 20000);
    plateau.setcase(&t3,34);

    Communaute co1("Communaute",&t3);
    plateau.setcase(&co1, 33);

    int loyer_t4[6]= {2600,13000,39000,90000,110000,127500};
    Terrain t4("vert", "avenue_foch", &co1, 30000, loyer_t4, 20000);
    plateau.setcase(&t4,32);

    int loyer_t5[6]= {2600,13000,39000,90000,110000,127500};
    Terrain t5("vert", "avenue_de_breuteuil", &t4, 30000, loyer_t5, 20000);
    plateau.setcase(&t5,31);

    GoPrison gp(&t5);
    plateau.setcase(&gp,30);

    int loyer_t6[6]= {2400,12000,36000,85000,102000,120000};
    Terrain t6("jaune", "rue_lafayette", &gp, 28000, loyer_t6, 15000);
    plateau.setcase(&t6,29);

    int loyer_comp1[6]= {0,0,0,0,0,0};
    Compagnie comp1("Compagnie_des_eaux",&t6,15000,loyer_comp1);
    plateau.setcase(&comp1,28);

    int loyer_t7[6]= {2200,11000,33000,80000,97500,115000};
    Terrain t7("jaune", "place_de_la_bourse", &comp1, 26000, loyer_t7, 15000);
    plateau.setcase(&t7,27);

   int loyer_t8[6] = {2200,11000,33000,80000,97500,115000};
    Terrain t8("jaune", "faubourg_saint-honore", &t7, 26000, loyer_t8, 15000);
    plateau.setcase(&t8,26);

    int loyer_g2[6] = {2500,5000,10000,20000, 0, 0};
    Gare g2("gare_du_nord", &t8, 20000, loyer_g2);
    plateau.setcase(&g2,25);

    int loyer_t9[6] = {2000,10000,30000,75000,92500,110000};
    Terrain t9("rouge", "avenue_henri-martin", &g2, 24000, loyer_t9, 15000);
    plateau.setcase(&t9,24);

    int loyer_t10[6] = {1800,9000,25000,70000,87500,105000};
    Terrain t10("rouge", "boulevard_malesgerbes", &t9, 22000, loyer_t10, 15000);
    plateau.setcase(&t10,23);

    Chance c2("Chance_2", &t10);
    plateau.setcase(&c2,22);

    int loyer_t11[6] = {1800,9000,25000,70000,87500,105000};
    Terrain t11("rouge", "avenue_matignon", &c2, 22000, loyer_t11, 15000);
    plateau.setcase(&t11,21);

    ParckGratuit pg(&t11, 0);
    plateau.setcase(&pg,20);

    int loyer_t12[6] = {1600,8000,22000,60000,80000,100000};
    Terrain t12("orange", "place_pigalle", &pg, 20000, loyer_t12, 10000);
    plateau.setcase(&t12,19);

    int loyer_t13[6] = {1400,7000,20000,55000,75000,95000};
    Terrain t13("orange", "boulevard_saint-michel", &t12, 18000, loyer_t12, 10000);
    plateau.setcase(&t13,18);

    Communaute co2("Communaute",&t13);
    plateau.setcase(&co2, 17);


    int loyer_t14[6] = {1400,7000,20000,55000,75000,95000};
    Terrain t14("orange", "avenue_mozart", &co2, 18000, loyer_t14, 10000);
    plateau.setcase(&t14,16);

    int loyer_g3[6] = {2500,5000,10000,20000, 0, 0};
    Gare g3("gare_de_lyon", &t14, 20000, loyer_g3);
    plateau.setcase(&g3,15);

    int loyer_t15[6] = {1200,6000,18000,50000,70000,90000};
    Terrain t15("violet", "rue_de_paradis", &g3, 16000, loyer_t15, 10000);
    plateau.setcase(&t15,14);

    int loyer_t16[6] = {1000,5000,15000,45000,62000,75000};
    Terrain t16("violet", "avenue_de_neuilly", &t15, 14000, loyer_t16, 10000);
    plateau.setcase(&t16,13);

    int loyer_comp2[6]= {0,0,0,0,0,0};
    Compagnie comp2("compagnie_d_electricite", &t16,15000,loyer_comp2);
    plateau.setcase(&comp2,12);

    int loyer_t17[6] = {1000,5000,15000,45000,62000,75000};
    Terrain t17("violet", "boulevard_de_la_villette", &comp2, 14000, loyer_t17, 10000);
    plateau.setcase(&t17,11);

    Prison pris1(&t17);
    plateau.setcase(&pris1,10);

    int loyer_t18[6] = {800,4000,10000,30000,45000,60000};
    Terrain t18("bleu clair", "avenue_de_la_republique", &pris1, 12000, loyer_t18, 5000);
    plateau.setcase(&t18,9);

    int loyer_t19[6] = {600,3000,9000,27000,40000,55000};
    Terrain t19("bleu clair", "rue_de_courcelles", &t18, 10000, loyer_t19, 5000);
    plateau.setcase(&t19,8);

    Chance c3("Chance_3", &t19);
    plateau.setcase(&c3,7);

    int loyer_t20[6] = {600,3000,9000,27000,40000,55000};
    Terrain t20("bleu clair", "rue_de_vaugirard", &c3, 10000, loyer_t20, 5000);
    plateau.setcase(&t20,6);

    int loyer_g4[6] = {2500,5000,10000,20000,0,0};
    Gare g4("gare_montparnasse", &t20, 20000, loyer_g4);
    plateau.setcase(&g4,5);

    Impot i2("impot_sur_le_revenu", &g4,20000);
    plateau.setcase(&i2,4);

    int loyer_t21[6] = {400,2000,6000,18000,32000,45000};
    Terrain t21("maron", "rue_lecourbe", &i2, 6000, loyer_t21, 5000);
    plateau.setcase(&t21,3);

    Communaute co3("Communaute",&t21);
    plateau.setcase(&co3, 2);

    int loyer_t22[6] = {200,1000,3000,9000,16000,25000};
    Terrain t22("maron", "boulevard_de_belleville", &co3, 6000, loyer_t22, 5000);
    plateau.setcase(&t22,1);

    dp.setSuivante(&t22);
    cout << "Plateau cree !" << endl;

    //  variable utile pour construire l'objet jeu
    int nbr_player;
    string player[8];
    string pion[8];
    int list_nb_joueurs[7] = {2,3,4,5,6,7,8};
    string list_pions[8] = {"cheval", "chapeau", "tour_eiffel", "tour_de_pise", "colise", "sagrada_familia", "clef", "voiture"};

    try {
        //  message de bienvenue
        cout << "\n\t\t Bienvenue dans le jeu Monopoly ! \n" << endl;

    //  choix du nombre de joueur
        cout << "Combien y aura-t-il de joueur ?:\n";
        cin >> nbr_player;
        while(nbr_player > 8){
            cout << "Impossible, le nombre maximum de joueur est de 8\n";
            cout << "Combien y aura-t-il de joueur ?:\n";
            cin >> nbr_player;
        }
        if (!is_in(nbr_player,list_nb_joueurs,7)){
            string error = "Error_entry_nb_player";
            throw error;
        }
        cout << "Nous jouerons donc une partie avec " << nbr_player << " joueurs " <<endl;

        Jeu J(plateau, 0);
        cout << "Voici les pions disponibles : cheval, chapeau, tour_eiffel, tour_de_pise, sagrada_familia, clef et voiture"<<endl;
    //  choix du nom de chaque joueur et du pion qui lui sera associe
        for(int i = 0; i < nbr_player; i++){
            cout << "Qui sera le joueur " << i + 1 << " :\n";
            cin >> player[i];
            cout << "Bonjour " << player[i] << ". Avec quel pion souhaites-tu jouer ?\n";
            string trypion;
            cin >> trypion;
            bool goodpion = false;
            if (i==0){
                while (!goodpion){
                    if (is_in(trypion,list_pions,8)){
                        goodpion = true;
                    }
                    else {
                        cout << "Desole ce pion n'existe pas, les pions possibles sont : cheval, chapeau, tour_eiffel, tour_de_pise, sagrada_familia, clef et voiture" << endl;
                        cout << "Avec quel pion souhaites-tu jouer " << player[i] << " ?\n";
                        cin >> trypion;
                    }
                }
            }
            while (!goodpion){
                if (is_in(trypion,list_pions,8) && !is_in(trypion,pion,i)){
                    goodpion = true;
                }
                else if (!is_in(trypion,list_pions,8)){
                    cout << "Desole ce pion n'existe pas, les pions possibles sont : cheval, chapeau, tour_eiffel, tour_de_pise, sagrada_familia, clef et voiture" << endl;
                    cout << "Avec quel pion souhaites-tu jouer " << player[i] << " ?\n";
                    cin >> trypion;
                }
                else if (is_in(trypion,pion,i)){
                    cout << "Desole, ce pion a deja ete choisi par un autre joueur" << endl;
                    cout << "Avec quel pion souhaites-tu jouer " << player[i] << " ?\n";
                    cin >> trypion;
                }
                else {
                    string error = "Error_config_pions_impossible";
                    throw error;
                }
            }
            pion[i] = trypion;
            cout << "Attribution du pion reussie !\n" << endl;
        }

        for(int i = 0; i < nbr_player; i++){
            J.create_joueur(player[i], pion[i]);
        }
        J.schedule();
    }
    catch(string Error){
        cout << "Error : " << Error << endl;
        cout << "Fin du jeu" << endl;
    }
    catch(...){
        cout << "Erreur lors du lancement du jeu" << endl;
        cout << "Veuillez contacter le service client pour resoudre ce probleme" << endl;
        cout << "Fin du jeu" << endl;
    }
    return 0;
}