//
// Created by heemin Kang on 2020/11/18.
//
#include <iostream>
#include "item.h"
#include "characterinfo.h"
using namespace std;

struct Item_list{
    int weapon;
    int armor;
    int potion;
};

void ItemDisplay_f(int round, Players &user) {
    Item_list display;
    char useritem_v;
    switch(round){
        case 1:
            display.weapon = rand()% 7 + 2;
            display.armor = rand()% 5 + 1;
            display.potion = rand() % 5 + 7;
            break;
        case 2:
            display.weapon = rand()% 7 + 5;
            display.armor = rand()% 5 + 3;
            display.potion = rand() % 5 + 8;
            break;
    }
    cout << "Weapon:(w) ";
    cout << display.weapon<<endl;
    cout << "Armor:(a) ";
    cout << display.armor<<endl;
    cout << "Potion:(p) ";
    cout << display.potion <<endl;
    cout << "select an item" << endl;
    cin >> useritem_v;
    switch(useritem_v){
        case 'w':
        case 'W':
            user.playerequipment_v.push_back(display.weapon+100);
            break;
        case 'a':
        case 'A':
            user.playerequipment_v.push_back(display.armor+200);
            break;
        case 'p':
        case 'P':
            user.playerequipment_v.push_back(display.potion+300);

    }

}