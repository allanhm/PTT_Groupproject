//
// Created by heemin Kang on 2020/11/07.
//
#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
using namespace std;
int main(){
    int game_option;
    cout << "        COMP2113/ENGG1340 Group-80 Project        " << endl;
    cout << "                  Deck Dungeon        " << endl;

    while(true){ // first display when it is start
        cout << "        Please choose optoins below        " << endl;
        cout << " 1. Create Profile" << endl;
        cout << " 2. Load Profile " << endl;
        cout << " 3. Exit" << endl;

        cin >> game_option;
        profile_creation(game_option);

    }




}