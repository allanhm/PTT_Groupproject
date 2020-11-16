#include <iostream>
#include <string>
#include <fstream>
#include "characterinfo.h"

using namespace std;
void load_f(Players users) {
    ifstream fin;
    users.playername_v += ".txt";
    fin.open(users.playername_v);
    fin >> users.playername_v;
    fin >> users.playerhp_v;
    fin >> users.playerlevel_v;
    fin >> users.playerattack_v;
    fin >> users.playerdefense_v;
    fin >> users.playerround_v;
    for(int i = 0 ; i < 3 ; i++) {
        fin >> users.playercard_v[i];
    }
    for(int i = 0 ; i < 3 ; i++) {
        fin >> users.equipment_v[i];
    }
    fin.close();
}

