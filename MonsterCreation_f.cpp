//
// Created by heemin Kang on 2020/11/17.
//
#include <iostream>
#include <string>
#include "MonsterCreation_f.h"
#include "characterinfo.h"
#include <cstdlib>
using namespace std;
void MonsterCreation_f( Monster &enemy){
    string monstername_set_v[5] = {"Mike Wazowski","James Sullivan","Pikachu","Kaf","Ian Holiday"};
    int pick = rand()%5;
    enemy.monstername = monstername_set_v[pick];
    enemy.monsterhp_v = 50;
}