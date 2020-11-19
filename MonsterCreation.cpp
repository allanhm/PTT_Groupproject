//
// Created by heemin Kang on 2020/11/17.
//
#include <string>
#include "MonsterCreation.h"
#include "characterinfo.h"
#include <cstdlib>
#include <ctime>
void MonsterCreation_f( Monster &enemy, int round){ // This function changes the monster's level for different rounds.
    std::string monstername_set_v[5] = {"Mike Wazowski","James Sullivan","Pikachu","Kaf","Ian Holiday"};
    srand((unsigned int)time(0));
    int pick = rand()%5;
    enemy.monstername_v = monstername_set_v[pick];
    enemy.monsterhp_v = 50;
    switch(round){
        case 1: // for round 1 monster's attack is 6, and defense is 1.
            enemy.monsterattack_v = 6;
            enemy.monsterdefense_v = 1;
            break; 
        case 2: // for round 2
            enemy.monsterattack_v = 8;
            enemy.monsterdefense_v = 3;
            break;
        case 3: // for round 3
            enemy.monsterattack_v = 12;
            enemy.monsterdefense_v = 6;
            break;
        case 4: // for round 4
            enemy.monsterattack_v = 15;
            enemy.monsterdefense_v = 9;
            break;
        case 5: // for round 5. The monster's attack and defense level increases, as the round progresses.
            enemy.monsterattack_v = 17;
            enemy.monsterdefense_v = 11;
            break;
    }
}
