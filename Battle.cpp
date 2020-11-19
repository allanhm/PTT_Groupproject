//
// Created by heemin Kang on 2020/11/17.
//

#include "Battle.h"
#include "characterinfo.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void CardDraw_f(int usercardhands[], int playerdeck[]);

void Redraw_f(int hands[], int deck[], int userselectedcard_v1);

void Sort_f(int hands[]);
void StatusAfterB_f(Players user, Monster mon);

void Battle_f(Players &user, Monster &enemy, int round, int userdeck[], int monsterdeck[]){ // player deack , monster
    int current_weapon = 0, current_armor = 0, item_option;
    vector<int> current_potion;
    for(int i = 0; i <user.playerequipment_v.size(); i++){
        if(user.playerequipment_v[i]/100 == 1){
            int weapon = user.playerequipment_v[i];
            current_weapon += (weapon%100);
        }
        else if(user.playerequipment_v[i]/100 == 2){
            int armor = user.playerequipment_v[i];
            current_armor += (armor);
        }
        else if(user.playerequipment_v[i]/100 == 3) {
            int potion = user.playerequipment_v[i] % 100;
            current_potion.push_back(potion);
        }
    }
    cout << "Welcome to round: " << user.playerround_v << endl; // round notification

    CardDraw_f(user.playercard_v,userdeck); // player draws 3 cards
    CardDraw_f(enemy.monstercard_v,monsterdeck); //monster draw 3 cards

    cout << user.playername_v << " drew 3 cards" << endl; // display player's card
    for(int i = 0 ; i < 3 ; i++) {
        cout << user.playercard_v[i] << ' ';
    }
    cout << endl;

    cout << enemy.monstername_v << " drew 3 cards"<< endl; // display monser's card
    for(int i = 0 ; i < 3 ; i++) {
        cout << enemy.monstercard_v[i] << ' ';
    }
    cout << endl;


    bool keepfight_v = true;
    while(keepfight_v) {
        cout <<"Item Phase" << endl;
        if(current_potion.size() ==0 ){
            cout<< "There is no potion you can use" <<endl<<endl;
        }
        else {
            cout << "Current Potion: ";
            for (int i = 0; i < current_potion.size(); i++) {
                cout << i+1 << "): " << current_potion[i] << ' ';
            }
            cout << endl;
            cout << "which one do want to you use?";
            cin >> item_option;
            user.playerhp_v += current_potion[item_option - 1];
                for(int j =0 ; j < user.playerequipment_v.size();j++){
                    if (current_potion[item_option - 1] == user.playerequipment_v[j] - 300 ){
                        user.playerequipment_v.erase(user.playerequipment_v.begin() + item_option -1);
                        current_potion.erase(current_potion.begin() + item_option -1);
                    }
                }
                if (user.playerhp_v >= 50) user.playerhp_v = 50;
                cout << "Your HP is " << user.playerhp_v << endl << endl;
            }



        cout << "Attack Phase" << endl;
        cout << "remaining cards: ";
        for(int i = 0 ; i < 3 ; i++) {
            cout << user.playercard_v[i] << ' ';
        }
        cout << endl;
        cout << user.playername_v << " please select a card to attack: ";
        int userselectedcard_v = 0;
        bool isonhands = false;
        while (!isonhands) {
            cin >> userselectedcard_v; //11
            cout << endl;
            for (int i = 0; i < 3; i++) { // take away the user's card
                if (user.playercard_v[i] == userselectedcard_v) {
                    user.playercard_v[i] = 0;
                    isonhands = true;
                    break;
                }
                if (i == 2) {
                    cout << "You picked the wrong number please pick again" << endl;
                }
            }
        }
        cout << enemy.monstername_v << " has selected a card!" << endl;

        cout << enemy.monstercard_v[0] << " " << enemy.monstercard_v[1] << " " << enemy.monstercard_v[2] << endl;



        int z = rand() % 2 + 1; // random pick from monster
        int monster_card_v = enemy.monstercard_v[z];
        cout << enemy.monstername_v << "'s card is " << monster_card_v << endl;
        for (int i = 0; i < 3; i++) { // take away the monster's card
            if (enemy.monstercard_v[i] == monster_card_v)
                enemy.monstercard_v[i] = 0;
        }

        int damage;
        // --------------------Comparing damage
        if (userselectedcard_v > monster_card_v) { //user wins
            cout << "You won!" << endl;
            damage = userselectedcard_v - enemy.monsterdefense_v+current_weapon;
            if (damage <= 0) damage =0;
            cout << damage << " damange to the monster!" << endl;
            enemy.monsterhp_v -= damage;
        }

        if (userselectedcard_v <= monster_card_v) { // monster wins
            cout << "You lost!" << endl;
            damage = monster_card_v - (user.playerdefense_v+current_armor);
            if (damage <= 0) damage =0;
            cout << damage << " damange to you!" << endl;
            user.playerhp_v -= damage;
        }
        StatusAfterB_f(user, enemy);

        // if either of the chcarters is down (which is hp < 0) cout << You or Monster loose keepfight => false
        if (user.playerhp_v <= 0) {
            cout << "You lost!" << endl;
            keepfight_v = false;
        }
        else if(enemy.monsterhp_v <= 0){
            cout << "You won!" << endl;
            keepfight_v = false;
        }
        Sort_f(user.playercard_v); // sort the player's card
        Sort_f(enemy.monstercard_v); // sort the monster's card
        Redraw_f(user.playercard_v, userdeck, userselectedcard_v);
        Redraw_f(enemy.monstercard_v, monsterdeck, monster_card_v);


        // if card num = 0, comapre cout << you win or loose keepfight false ( Card is 0)
        int numof0_v=0;
        for (int i = 0; i < 20; i++) {
            if (userdeck[i] == 0)
                numof0_v++;
        }
        if (numof0_v==20 && user.playerhp_v > enemy.monsterhp_v) { // 모든 댁의 카드가 0이면 numof0_v=20
            cout << "You won!" << endl;
            keepfight_v = false;
        }
        else if (numof0_v==20 && userselectedcard_v <= enemy.monstercard_v[z]) {
            cout << "You lost!" << endl;
            keepfight_v = false;
        }

        }
    }



void CardDraw_f(int usercardhands[], int playerdeck[]){
    random_device rd; //random_device for seed value
    minstd_rand gen(rd());
    uniform_int_distribution<int> dis(1,20);

    int i = 0, max =3;
    for (;i < max; i++){
        usercardhands[i] =dis(gen);
        for(int j = 0;j<i;j++){
            if (usercardhands[i] == usercardhands[j]){
                i--;
                break;
            }
        }
        playerdeck[usercardhands[i]] = 0;
    }
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

void Redraw_f(int why[], int check[]) {
    bool isoverlapped = true;
    random_device rd;
  
    while (isoverlapped) {
        minstd_rand gen(rd());
        uniform_int_distribution<int> dis(1, 20);
        int redraw = dis(gen);
        int i = 1;
        if (check[redraw] == i){
            why[0] = redraw;
            check[redraw] = 0;
            isoverlapped = false;
            }
        else isoverlapped =true;
        }
    }



void Sort_f(int hands[]){
    int i , j, temp;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(hands[i]>hands[j])
            {
                temp = hands[i];
                hands[i]=hands[j];
                hands[j]=temp;
            }
        }
    } //sorting in ascending order.
}
