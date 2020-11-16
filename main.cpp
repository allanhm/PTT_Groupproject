//
// Created by heemin Kang on 2020/11/07.
//
#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
#include "characterinfo.h"
#include "MonsterCreation.h"
using namespace std;


int main(){
    int game_option;
    Players user;
    cout << "        COMP2113/ENGG1340 Group-80 Project        " << endl;
    cout << "                  Deck Dungeon        " << endl;

    while(true){ // first display when it is start
        cout << "        Please choose optoins below        " << endl;
        cout << " 1. Create Profile" << endl;
        cout << " 2. Load Profile " << endl;
        cout << " 3. Exit" << endl;
        cout << "Your Option: " ;
        cin >> game_option;
        if (game_option < 1 || game_option > 3){
            cout << " Wrong option ! Please press other keys"<<endl;
        }
        else{
            if (!profile_creation(game_option, user)){
                break;
            }
        }


    }
    cout << "Round 1 "<< endl;
    Monster enemy;
    MonsterCreation_f(enemy,1);
    cout << enemy.monstername_v << " appeared!";






}