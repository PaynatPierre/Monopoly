#ifndef COMMUNAUTE_H
#define COMMUNAUTE_H

#include <string>
#include "Case.h"
using namespace std;


class Communaute: public Case {
private: 
	string m_carteCommunaute[16];

public:
    void jouerCommunaute();
    string getCarteCommunaute(int i);
    void setCarteCommunaute(int i, string name);

};





#endif