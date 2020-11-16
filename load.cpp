#include <iostream>
#include <string>
#include <fstream>
#include "characterinfo.h"

using namespace std;
void load_f(Players &user) {
    ifstream fin;
    user.playername_v += ".txt";
    fin.open(user.playername_v);
    fin >> user.playername_v;
    fin >> user.playerhp_v;
    fin >> user.playerlevel_v;
    fin >> user.playerattack_v;
    fin >> user.playerdefense_v;
    fin >> user.playerround_v;
    for(int i = 0 ; i < 3 ; i++) {
        fin >> user.playercard_v[i];
    }
    for(int i = 0 ; i < 3 ; i++) {
        fin >> user.playerequipment_v[i];
    }
    fin.close();
}

