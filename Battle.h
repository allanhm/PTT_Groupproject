//
// Created by heemin Kang on 2020/11/17.
//

#ifndef GROUP_80_BATTLE_H
#define GROUP_80_BATTLE_H
#include "characterinfo.h"

void Battle_f(Players &user, Monster &enemy, int round, int userdeck[], int monsterdeck[]);\


void StatusAfterBPlyaer_f(int current_weapon, int current_armor,Players player);

void ItemList_f(int &current_weapon, int &current_armor, Players &user);
#endif //GROUP_80_BATTLE_H
