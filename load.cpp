#include <iostream>
#include <string>
#include <fstream>
#include "characterinfo.h"
#include "createprofile.h"

using namespace std;
void load_f(Players &user) {
    int index =0;
    ifstream fin;
    string file = user.playername_v + ".txt";
    fin.open(file); // save hp, attack, defense , card, equipment, round
    cout << "Character name: " << user.playername_v << endl;
    fin >> user.playerhp_v;

    fin >> user.playerround_v;
    cout << "Current round: " << user.playerround_v << endl;

    cout << "-----Player Status-----" << endl;
    cout << "HP: " << user.playerhp_v << " / 50" << endl;
    fin >> user.playerattack_v;
    cout << "Damage: " <<  user.playerattack_v<< endl;
    fin >> user.playerdefense_v;
    cout << "Defense: " << user.playerdefense_v << endl;

    cout << "Item info: " << endl;
    int item;
    while(fin >> item){
        user.playerequipment_v.push_back(item);
    }
    int current_weapon = 0, current_armor = 0, item_option;
    vector<int> current_potion;
    for(int i = 0; i <user.playerequipment_v.size(); i++){
        if(user.playerequipment_v[i]/100 == 1){
            int weapon = user.playerequipment_v[i]%100;
            current_weapon += (weapon);
        }
        else if(user.playerequipment_v[i]/100 == 2){
            int armor = user.playerequipment_v[i]%200;
            current_armor += (armor);
        }
        else if(user.playerequipment_v[i]/100 == 3) {
            int potion = user.playerequipment_v[i] % 100;
            index++;
        }
    }
    cout << "weapon damage: " << current_weapon << endl;
    cout << "armor defense: " << current_armor << endl;
    cout << "potion: " << index << " bottle(s)"<< endl;
    cout << "-------------------"<< endl;
    fin.close();

}

