//
// Created by heemin Kang on 2020/11/17.
//

#include "Battle.h"
#include "Characterinfo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void PlayerCardDraw_f(Players &user, int i){
    srand((unsigned int)time(0));
    int i_v, compare_i_v;
    for (i_v = 0 ; i_v < 3; i_v ++){
        user.playercard_v[i] = rand() % 21; // randomly assign the card
        for(compare_i_v = 0; compare_i_v < i_v; compare_i_v++){
            if (user.playercard_v[i_v] == user.playercard_v[compare_i_v]){ // if there is a same card re_draw;
                i_v--;
                break;
            }
        }
        playerdeck[user.playercard_v[i]] = 0;
    }
}

void PlayerReDraw(){
    srand((unsigned int)time(0));

}
void MonsterCardDraw_f(Monster &mon, int round_num){

}
void Battle_f(Players &user, Monster &enemy, int round, int userdeck[], int monsterdeck[]){ // player deack , monster
    cout << "Welcome to round: " << user.playerround_v << endl; // round notification
    //Card Draw
    cout << enemy.monstername_v << "'s card: " << "? ? ?" << endl; // monster card

    cout << user.playername_v << "'s card: "; // user's card
    for(int i = 0 ; i < 3 ; i++) {
        cout << user.playercard_v[i] << ' ';
    }
    cout << "\n";

    cout << enemy.monstername_v << " has selected a card!" << endl;


    cout << user.playername_v << " please select a card to attack: ";

    int userselectedcard_v= 0;
    cin >> userselectedcard_v;
    cout << endl;

    for(int i = 0 ; i < 3 ; i++) { // take away the user's card
        if (user.playercard_v[i] == userselectedcard_v)
            user.playercard_v[i] = 0;
    }

    int n = sizeof(enemy.monstercard_v)/sizeof(enemy.monstercard_v[0]);
    sort(enemy.monstercard_v, enemy.monstercard_v+n); //sorting in ascending order.
    int z= rand() % 2 + 1;

    cout << enemy.monstername_v << "'s card is" << enemy.monstercard_v[z] << endl;

    if (userselectedcard_v > enemy.monstercard_v[z]) {
        cout << "You won!" << endl;
        cout << user.playerattack_v << " damange to the monster!" << endl;
        enemy.monsterhp_v= enemy.monsterhp_v - user.playerattack_v +enemy.monsterdefense_v;
        cout << "——Monster Status——" << endl;
        cout << "HP: " << user.playerhp_v << " / 50" << endl;
        cout << "Damage: " <<  user.playerattack_v<< endl;
        cout << "Defense: " << user.playerdefense_v << endl;
    }


}