//
// Created by heemin Kang on 2020/11/17.
//

#include "Battle.h"
#include "characterinfo.h"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void CardDraw_f(int usercardhands[], int playerdeck[]){
    random_device rd; //random_device for seed value

    minstd_rand gen(rd());
    uniform_int_distribution<int> dis(1,20);
    int i_v, compare_i_v;
    for (i_v = 0 ; i_v < 3; i_v ++){
        usercardhands[i_v] = dis(gen); // randomly assign the card
        for(compare_i_v = 0; compare_i_v < i_v; compare_i_v++){
            if (usercardhands[i_v] == playerdeck[compare_i_v]){ // if there is a same card re_draw;
                i_v--;
                break;
            }
        }
        playerdeck[usercardhands[i_v]] = 0;
        }
    }

void PlayerReDraw(){
    srand((unsigned int)time(0));


}

void StatusAfterB_f(Players user, Monster mon){
    cout << "——Monster Status——" << endl;
    cout << "HP: " << mon.monsterhp_v << " / 50" << endl;
    cout << "Damage: " <<  mon.monsterattack_v << endl;
    cout << "Defense: " << mon.monsterdefense_v << endl;
    cout << "——User Status——" << endl;
    cout << "HP: " << user.playerhp_v << " / 50" << endl;
    cout << "Damage: " <<  user.playerattack_v<< endl;
    cout << "Defense: " << user.playerdefense_v << endl;

}

void Battle_f(Players &user, Monster &enemy, int round, int userdeck[], int monsterdeck[]){ // player deack , monster
    cout << "Welcome to round: " << user.playerround_v << endl; // round notification

    CardDraw_f(user.playercard_v,userdeck); // player draws 3 cards
    cout << enemy.monstername_v << " drew 3 cards"<< endl;
    cout << user.playername_v << "'s card: "; // user's card
    for(int i = 0 ; i < 3 ; i++) {
        cout << user.playercard_v[i] << ' ';
    }

    cout << enemy.monstername_v << " drew 3 cards" << endl;
    cout << enemy.monstername_v << "'s card: " << "? ? ?" << endl; // monster's card unknown.
    CardDraw_f(enemy.monstercard_v,monsterdeck); //monster draw 3 cards
    for(int i = 0 ; i < 3 ; i++) {
        cout << enemy.monstercard_v[i] << ' ';
    }
    cout << "\n";
    // loop -> fight until one side is down or if there are no more cards to draw.
    cout << "Attack Phase" << endl;

    cout << user.playername_v << " please select a card to attack: ";
    int userselectedcard_v= 0;
    bool isonhands = false;
    while(!isonhands){
        cin >> userselectedcard_v; //11
        cout << endl;
        for(int i = 0 ; i < 3 ; i++) { // take away the user's card
            if (user.playercard_v[i] == userselectedcard_v){
                user.playercard_v[i] = 0;
                isonhands = true;
                break;
            }
            if (i==2){
                cout << "You pciekd wrong number please pick again" <<endl;
            }
        }
    }
    cout << enemy.monstername_v << " has selected a card!" << endl;
    int n = sizeof(enemy.monstercard_v)/sizeof(enemy.monstercard_v[0]);
    sort(enemy.monstercard_v, enemy.monstercard_v+n); //sorting in ascending order.
    int z= rand() % 2 + 1;
    cout << enemy.monstercard_v[0] << " " << enemy.monstercard_v[1] << " " << enemy.monstercard_v[2] << endl;

    cout << enemy.monstername_v << "'s card is" << enemy.monstercard_v[z] << endl;

    if (userselectedcard_v > enemy.monstercard_v[z]) { //user wins
        cout << "You won!" << endl;
        cout << user.playerattack_v << " damange to the monster!" << endl;
        enemy.monsterhp_v= enemy.monsterhp_v - user.playerattack_v + enemy.monsterdefense_v;
    }
    
    if (userselectedcard_v <= enemy.monstercard_v[z]) { // monster wins
        cout << "You lost!" << endl;
        cout << enemy.monsterattack_v << " damange to you!" << endl;
        user.playerhp_v = user.playerhp_v - enemy.monsterattack_v + enemy.monsterdefense_v;
    }
    StatusAfterB_f(user, enemy);
    
    for(int i = 0 ; i < 3 ; i++) { // take away the monster's card
        if (enemy.monstercard_v[i] == enemy.monstercard_v[z])
            enemy.monstercard_v[i] = 0;
    }
     
}
