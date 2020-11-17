#include <iostream>
#include <string>
#include <fstream>
#include "characterinfo.h"
#include "createprofile.h"

using namespace std;
void load_f(Players &user) {
    ifstream fin;
    string file = user.playername_v + ".txt";
    fin.open(file); // save hp, attack, defense , card, equipment, round
    cout << "Character name: " << user.playername_v << endl;
    fin >> user.playerhp_v;
    cout << "-----Player Status-----" << endl;
    cout << "HP: " << user.playerhp_v << " / 50" << endl;
    fin >> user.playerlevel_v;
    cout << "Level: " << user.playerlevel_v << endl;
    fin >> user.playerattack_v;
    cout << "Damage: " <<  user.playerattack_v<< endl;
    fin >> user.playerdefense_v;
    cout << "Defense: " << user.playerdefense_v << endl;
    fin >> user.playerround_v;
    cout << "Current round: " << user.playerround_v << endl;
    cout << "Card number: ";
    for(int i = 0 ; i < 3 ; i++) {
        fin >> user.playercard_v[i];
        cout << user.playercard_v[i] << ' ';
    }
    cout << endl;
    for(int i = 0 ; i < 3 ; i++) {
        fin >> user.playerequipment_v[i];
    }
    cout << "-------------------"<< endl;
    fin.close();
}

