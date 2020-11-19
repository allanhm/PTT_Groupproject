//
// Created by heemin Kang on 2020/11/07.
//
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include "createprofile.h"
#include "characterinfo.h"
#include "MonsterCreation.h"
#include "save.h"
#include "Battle.h"
#include "item.h"

using namespace std;


int main(){
    Players user; // Create structure to contain character information
    string game_option;
    bool repeat = true;
    
    cout << "        COMP2113/ENGG1340 Group-80 Project        " << endl; //// first display when it is start
    cout << "                  Deck Dungeon        " << endl;
    
    while(repeat){  //in case of pressing wrong key
        cout << "        Please choose optoins below        " << endl;
        cout << " 1. Create Profile" << endl;
        cout << " 2. Load Profile " << endl;
        cout << " 3. Exit" << endl;
        cout << "Your Option: " ;
        cin >> game_option;
        if(game_option.length()>1){
            cout << "You can press only one key! Please trying again\n\n\n\n";
            continue;
        }
        
        char selection = game_option[0];
        repeat = profile_creation(selection, user); // based on the option it will helps to create
        }                                                     // load file or terminate the game

    Monster enemy; // create a monster structure to use in the rest of the game.
    char saveindex; // bsed on the input
    for(; user.playerround_v < 6; user.playerround_v++){
        int round = user.playerround_v;
        int playerdeck[21]; // creating a deck for each rounds
        int monsterdeck[21];

        fill_n(playerdeck, 21, 1);
        fill_n(monsterdeck, 21, 1);

        cout << "Round"<< user.playerround_v <<  endl;
        MonsterCreation_f(enemy,round); // monster is created for each round
        cout << enemy.monstername_v << " appeared!" << endl;
        
        Battle_f(user, enemy,round,playerdeck,monsterdeck);

        if(user.playerround_v<5){ // After Last round player cannot save the game.
            ItemDisplay_f(round, user);
        }
        
        cout << "Do you want to Save & Quit? (Y/N) ";
        cin >> saveindex;
        
        if(saveindex == 'Y'|| saveindex == 'y'){
            save_f(user);
        }
        
        else{
            cout << "Game goes on..." << endl;
        }
    }
    
    cout << "End of Game" << endl;
    
    if(saveindex == 'Y'|| saveindex == 'y'){
        save_f(user);
    }
    
    else{
        cout << "Game is terminated without being saved. Thank you!" << endl;;
    }
    return 0;
}
