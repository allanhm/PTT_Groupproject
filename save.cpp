#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "characterinfo.h"
#include "createprofile.h"
using namespace std;
void save_f(Players &user) {
    ofstream write;
    string filename = user.playername_v + ".txt";
    write.open(filename); // save hp, attack, defense , card, equipment, round
    write << user.playerhp_v << endl;
    write << user.playerround_v << endl;
    write << user.playerattack_v << endl;
    write << user.playerdefense_v << endl;
    for (auto itr = user.playerequipment_v.begin(); itr != user.playerequipment_v.end(); ++itr)
    {
        write << *itr << endl;
    }


    
    write.close();

    cout << "Save successfully complete! Bye Bye!" << endl;
    exit(1);
}
