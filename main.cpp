//
// Created by heemin Kang on 2020/11/07.
//
#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
using namespace std;


struct Player{
    string plyaername_v;
    int plyaerhp_v;
    int playerlevel_v;
    int playerattack_v;
    int plyaerdefense_v;
    int plyaercard_v[3];
    int equipment_v[3];

};


struct Monster{
    string monstername;
    int Monsterhp_v;
    int attack_v;
    int defense_v;
    int card[3];
};

int main(){
    int game_option;
    Player user;
    cout << "        COMP2113/ENGG1340 Group-80 Project        " << endl;
    cout << "                  Deck Dungeon        " << endl;

    while(true){ // first display when it is start
        cout << "        Please choose optoins below        " << endl;
        cout << " 1. Create Profile" << endl;
        cout << " 2. Load Profile " << endl;
        cout << " 3. Exit" << endl;
        cin >> game_option;
        profile_creation(game_option, user);

    }




}