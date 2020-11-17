//
// Created by heemin Kang on 2020/11/07.
//
#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
#include "characterinfo.h"
#include "MonsterCreation.h"
#include "save.h"
#include "Battle.h"
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
    Monster enemy;
    char saveindex;
    for(; user.playerround_v < 4; user.playerround_v++){
        int round = user.playerround_v;
        cout << "Do you want to Save & Quit? (Y/N)";
        cin >> saveindex;
        if(saveindex == 'Y'|| saveindex == 'y'){
            save_f(user);
        }
        else{
            cout << "Game goes on..";
        }
        int playerdeck[21] = {1};
        int monsterdeck[21] = {1};

        cout << "Round"<< user.playerround_v <<  endl;
        MonsterCreation_f(enemy,round);
        cout << enemy.monstername_v << " appeared!";
        Battle_f(user, enemy,round,playerdeck,monsterdeck){

        }

    }







}