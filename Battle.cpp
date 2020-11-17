//
// Created by heemin Kang on 2020/11/17.
//

#include "Battle.h"
#include "Characterinfo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void PlayerCardDraw_f(){
    srand((unsigned int)time(0));
}

void MonsterCardDraw_f(){

}
void Battle_f(Players &user, Monster &enemy, int round){
    cout << "Welcome to round: " << user.playerround_v << endl;
    
    cout << enemy.monstername_v << "'s card: " << "? ? ?" << endl;
    
    cout << user.playername_v << "'s card: ";
    for(int i = 0 ; i < 3 ; i++) {
            cout << user.playercard_v[i] << ' ';
        }
    cout << "\n";
    
    cout << enemy.monstername_v << " has selected a card!" << endl;

    
    cout << user.playername_v << " please select a card to attack: ";
    
    int userselectedcard_v= 0;
    cin >> userselectedcard_v >> endl;
    
    for(int i = 0 ; i < 3 ; i++) {
        if (user.playercard_v[i] == userselectedcard_v)
            user.playercard_v[i] = 0;
        }
    
    int n = sizeof(monstercard_v)/sizeof(monstercard_v[0]);
    sort(monstercard_v, monstercard_v+n);
    int z= rand() % 2;

    cout << enemy.monstername_v << "'s card is" << monstercard_v[z] << endl;
    
    if (userselectedcard_v > monstercard_v[z]) {
        cout << "You won!" << endl;
        cout << playerattack_v << " damange to the monster!" << endl;
        monsterhp_v= monsterhp_v - playerattack_v;
        cout << "-----Monster Status-----" << endl;
        cout << "HP: " << user.playerhp_v << " / 50" << endl;
        cout << "Damage: " <<  user.playerattack_v<< endl;
        cout << "Defense: " << user.playerdefense_v << endl;
    }

    
    }
}
