//
// Created by heemin Kang on 2020/11/18.
//
#include <iostream>
#include "item.h"
#include "characterinfo.h"
using namespace std;

struct Item_list{ // structure to store different type of items.
    int weapon;
    int armor;
    int potion;
};

void ItemDisplay_f(int round, Players &user) {
    Item_list display;
    char useritem_v;
    switch(round){ // Random strength assigned to each item after the end of each round
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
        case 3:
            display.weapon = rand()% 7 + 8;
            display.armor = rand()% 5 + 5;
            display.potion = rand() % 5 + 10;
            break;
        case 4:
            display.weapon = rand()% 7 + 9;
            display.armor = rand()% 5 + 7;
            display.potion = rand() % 5 + 11;
            break;
    }
    
    cout << "Weapon:(w) ";
    cout << display.weapon<<endl;
    cout << "Armor:(a) ";
    cout << display.armor<<endl;
    cout << "Potion:(p) ";
    cout << display.potion <<endl;
    cout << "Please select an item: ";
    cin >> useritem_v;
    
    switch(useritem_v){
        case 'w':
        case 'W':
            user.playerequipment_v.push_back(display.weapon+100); // Stores the strength assigned to the playerequipment_v vector.
            break;
        case 'a':
        case 'A':
            user.playerequipment_v.push_back(display.armor+200); // Stores the strength assigned to the playerequipment_v vector.
            break;
        case 'p':
        case 'P':
            user.playerequipment_v.push_back(display.potion+300); // Stores the strength assigned to the playerequipment_v vector.
    }

}
