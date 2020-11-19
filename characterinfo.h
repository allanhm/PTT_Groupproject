//
// Created by heemin Kang on 2020/11/17.
//

#ifndef GROUP_80_CHARACTERINFO_H
#define GROUP_80_CHARACTERINFO_H
#include <iostream>
#include <vector>

struct Players{ //Structure to store player's information. The integer values written are the default level of the player.
    std::string playername_v;
    int playerhp_v = 50;
    int playerattack_v = 0;
    int playerdefense_v = 10;
    int playercard_v[3] = {};
    std::vector<int> playerequipment_v;
    int playerround_v = 1;

};

struct Monster{ // Structure to store monster's information. The integer values written are the default level of the monster.
    std::string monstername_v;
    int monsterhp_v;
    int monsterattack_v;
    int monsterdefense_v;
    int monstercard_v[3] = {};
};
#endif //GROUP_80_CHARACTERINFO_H
