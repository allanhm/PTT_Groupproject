#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

#include "characterinfo.h"
using namespace std;
void load_f() {
    ifstream fin;
    fin.open("save.txt");
    fin >> Player.plyaername_v;
    fin >> Player.plyaerhp_v;
    fin >> Player.playerlevel_v;
    fin >> Player.playerattack_v;
    fin >> Player.plyaerdefense_v;
    fin >> Player.plyaercard_v[3];
    fin >> Player.equipment_v[3];
    fin.close();
}
    

