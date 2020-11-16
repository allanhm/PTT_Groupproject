#include <iostream>
#include <string>
#include <fstream>
#include "characterinfo.h"

using namespace std;
void load_f(Players users) {
    ifstream fin;
    fin.open("save.txt");
    fin >> users.plyaername_v;
    fin >> users.plyaerhp_v;
    fin >> users.playerlevel_v;
    fin >> users.playerattack_v;
    fin >> users.plyaerdefense_v;
    for(int i = 0 ; i < 3 ; i++) {
        fin >> users.plyaercard_v[i];
    }
    for(int i = 0 ; i < 3 ; i++) {
        fin >> users.equipment_v[i];
    }
    fin.close();
}

