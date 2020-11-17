//
// Created by heemin Kang on 2020/11/17.
//

#ifndef GROUP_80_CHARACTERINFO_H
#define GROUP_80_CHARACTERINFO_H

struct Players{ //Default value when new characgter is made
    std::string playername_v;
    int playerhp_v = 50;
    int playerattack_v = 7;
    int playerdefense_v = 3;
    int playercard_v[3] = {0};
    int playerequipment_v[3] = {0};
    int playerround_v = 1;

};


struct Monster{
    std::string monstername_v;
    int monsterhp_v;
    int monsterattack_v;
    int monsterdefense_v;
    int monstercard_v[3];
};
#endif //GROUP_80_CHARACTERINFO_H
