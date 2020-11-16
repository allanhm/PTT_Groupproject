//
// Created by heemin Kang on 2020/11/17.
//

#ifndef GROUP_80_CHARACTERINFO_H
#define GROUP_80_CHARACTERINFO_H

struct Players{ //Default value when new characgter is made
    std::string playername_v;
    int playerhp_v = 50;
    int playerlevel_v = 1;
    int playerattack_v = 7;
    int playerdefense_v = 3;
    int playercard_v[3] = {0};
    int playerequipment_v[3] = {0};
    int playerround = 1;

};


struct Monster{
    std::string monstername;
    int monsterhp_v;
    int monsterattack_v;
    int monsterdefense_v;
    int monstercard[3];
};
#endif //GROUP_80_CHARACTERINFO_H
