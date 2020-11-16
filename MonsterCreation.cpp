//
// Created by heemin Kang on 2020/11/17.
//
#include <iostream>
#include <string>
#include "MonsterCreation.h"
#include "characterinfo.h"
#include <cstdlib>
void MonsterCreation_f( Monster &enemy, int round){
    std::string monstername_set_v[5] = {"Mike Wazowski","James Sullivan","Pikachu","Kaf","Ian Holiday"};
    int pick = rand()%5;
    enemy.monstername_v = monstername_set_v[pick];
    enemy.monsterhp_v = 50;
    switch(round){
        case 1:
            enemy.monsterattack_v = 6;
            enemy.monsterdefense_v = 1;
            break;
        case 2:
            enemy.monsterattack_v = 10;
            enemy.monsterdefense_v = 3;
            break;
        case 3:
            enemy.monsterattack_v = 15;
            enemy.monsterdefense_v = 7;
            break;
    }
}
