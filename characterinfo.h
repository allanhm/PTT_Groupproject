//
// Created by heemin Kang on 2020/11/17.
//

#ifndef GROUP_80_CHARACTERINFO_H
#define GROUP_80_CHARACTERINFO_H

struct Players{
    std::string plyaername_v;
    int plyaerhp_v;
    int playerlevel_v;
    int playerattack_v;
    int plyaerdefense_v;
    int plyaercard_v[3];
    int equipment_v[3];

};


struct Monster{
    std::string monstername;
    int Monsterhp_v;
    int attack_v;
    int defense_v;
    int card[3];
};
#endif //GROUP_80_CHARACTERINFO_H
