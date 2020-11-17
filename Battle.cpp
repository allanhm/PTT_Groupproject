//
// Created by heemin Kang on 2020/11/17.
//

#include "Battle.h"
#include "Characterinfo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Battle_f(Players &user, Monster &enemy, int round){
    srand((unsigned int)time(0));
    int player_deck_v[21] ={1}, monster_decl_v[21] = {1};

    switch(round){
        case 1:
            for (int i =1; i < 3; i++){
                user.playercard_v[i] = rand()%21;
                int index = user.playercard_v[i];
                player_deck_v[user.playercard_v[i]] = 0;
                enemy.monstercard_v = rand()%21;
                player_deck_v[user.playercard_v[i]] = 0;
            }
    }
}