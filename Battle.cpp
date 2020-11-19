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

void CardDraw_f(int usercardhands[], int playerdeck[]); // declaration of the function

void Redraw_f(int playerhand[], int playerdeck[]); // declaration of the function

void Sort_f(int hands[]);  // declaration of the function

void StatusAfterBPlyaer_f(int current_weapon, int current_armor,Players player);  // declaration of the function

void StatusAFterBMonster_f(Monster enemy); // declaration of the function

void ItemList_f(int &current_weapon, int &current_armor, Players &user);

void Battle_f(Players &user, Monster &enemy, int round, int userdeck[], int monsterdeck[]){ // player deack , monster
    int c_weapon = 0, c_armor = 0, item_option;
    vector<int> current_potion;
    ItemList_f(c_weapon,c_armor,user);
    for(int i = 0; i <user.playerequipment_v.size(); i++){  // The strength of the items are saved in the text file as 1?? for weapon, 2?? for armor, 3?? for potion. This loop function compares the first digit of the three and updates the strengths of the weapons.
        if(user.playerequipment_v[i]/100 == 3) {
            int potion = user.playerequipment_v[i] % 100;
            current_potion.push_back(potion);
        }
    }

    CardDraw_f(user.playercard_v,userdeck); // player draws 3 cards
    CardDraw_f(enemy.monstercard_v,monsterdeck); //monster draw 3 cards

    cout << user.playername_v << " drew 3 cards\n\n"; // display player's card
    for(int i = 0 ; i < 3 ; i++) {
        cout << user.playercard_v[i] << ' ';
    }
    cout << endl;
    cout << enemy.monstername_v << " drew 3 cards\n\n"; // display monser's card
    cout << endl;

    bool keepfight_v = true;
    while(keepfight_v) {
        cout <<"-----Item Phase-----" << endl;
        if(current_potion.size() ==0 ){
            cout<< "There is no potion you can use\n\n";// shows that there are no potion available
        }
        else {
            cout << "Current Potion: ";
            for (int i = 0; i < current_potion.size(); i++) {
                cout << i+1 << "): " << current_potion[i] << ' ';
            }
            cout << endl;
            cout << "which one do want to you use?";
            cin >> item_option; // User selects the item
            int option = item_option -1;
            user.playerhp_v += current_potion[option];
                for(int j =0 ; j < user.playerequipment_v.size();j++){ // evaluates the different types of items
                    if (current_potion[option] == user.playerequipment_v[j] - 300 ){
                        user.playerequipment_v.erase(user.playerequipment_v.begin() + j);
                        current_potion.erase(current_potion.begin()+option);
                    }
                }
                if (user.playerhp_v >= 50) user.playerhp_v = 50;
                cout << "Your HP is now " << user.playerhp_v << endl << endl;
            }

        StatusAfterBPlyaer_f(c_weapon, c_armor, user);

        StatusAFterBMonster_f(enemy);

        cout << "-----Attack Phase-----" << endl;
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
                if (user.playercard_v[i] == userselectedcard_v) { // This if function evaluates whether the user inputted number is equal to one of the numbers in the user's hands.
                    user.playercard_v[i] = 0; // If it is the same, the card number in the userhands array becomes zero.
                    isonhands = true;
                    break;
                }
                if (i == 2) {
                    cout << "You picked the wrong number please pick again: ";
                }
            }
        }
        cout << enemy.monstername_v << " has selected a card!" << endl;


        int z = rand() % 2 + 1; // random pick from monster
        int monster_card_v = enemy.monstercard_v[z];
        cout << enemy.monstername_v << "'s card is " << monster_card_v << endl;
        cout << endl;
        
        for (int i = 0; i < 3; i++) { // take away the monster's card by assigning zero to the monster's hands. Same method as the user.
            if (enemy.monstercard_v[i] == monster_card_v)
                enemy.monstercard_v[i] = 0;
        }

        int damage;
        // --------------------Comparing damage
        if (userselectedcard_v > monster_card_v) { //user wins
            cout << "-----You won!-----" << endl;
            damage = userselectedcard_v - enemy.monsterdefense_v+c_weapon;// calculates the damage
            if (damage <= 0) damage =0;
            cout << damage << " damange to the monster!" << endl;
            cout << endl;
            enemy.monsterhp_v -= damage;
        }

        if (userselectedcard_v <= monster_card_v) { // monster wins
            cout << "-----You lost!-----" << endl;
            damage = monster_card_v - (user.playerdefense_v+c_armor); // calculates the damage
            if (damage <= 0) damage =0;
            cout << damage << " damange to you!" << endl;
            cout << endl;
            user.playerhp_v -= damage;
        }


        // if either of the chcarters is down (which is hp < 0) cout << You or Monster loose keepfight => false
        if (user.playerhp_v <= 0) {
            cout << "-----You lost!-----" << endl;
            keepfight_v = false;
        }
        else if(enemy.monsterhp_v <= 0){
            cout << "-----You won!-----" << endl;
            keepfight_v = false;
        }

        Sort_f(user.playercard_v); // sort the player's card
        Sort_f(enemy.monstercard_v); // sort the monster's card

        Redraw_f(user.playercard_v, userdeck); // Redrawing the card to fill in the card that the user has used.
        Redraw_f(enemy.monstercard_v, monsterdeck); // Redrawing the card to fill in the card that the monster has used.


        // if card num = 0, comapre cout << you win or loose keepfight false (Card is 0)
        int numof0_v=0;
        for (int i = 0; i < 20; i++) {
            if (userdeck[i] == 0)
                numof0_v++;
        }
        if (numof0_v==20 && user.playerhp_v > enemy.monsterhp_v) { // If all of the cards are assigned as 0(numof0_v==20), that means all the cards in the deck are used. After that process, compare the user and monster HP to decide who wins or loses.
            cout << "-----You won!-----" << endl;
            keepfight_v = false;
        }
        else if (numof0_v==20 && userselectedcard_v <= enemy.monstercard_v[z]) {
            cout << "-----You lost!-----" << endl;
            keepfight_v = false;
        }

        }
    }

void CardDraw_f(int usercardhands[], int playerdeck[]){ // This function assigns the random card for the user and the monster.
    random_device rd; //random_device for seed value
    minstd_rand gen(rd());
    uniform_int_distribution<int> dis(1,20);

    int i = 0, max =3;
    for (;i < max; i++){ // Assigns 3 different cards to the user or the monster
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

void StatusAfterBPlyaer_f(int current_weapon, int current_armor,Players player){ // displays the current status of the user
    cout << "-----User Status-----" << endl;
    cout << "HP: " << player.playerhp_v << " / 50" << endl;
    cout << "Damage: " <<  player.playerattack_v<< " + " << current_weapon<< endl;
    cout << "Defense: " << player.playerdefense_v << " + " << current_armor << endl;
    cout << endl;
}

void StatusAFterBMonster_f(Monster mon){ // displays the current status of the monster
    cout << "-----Monster Status-----" << endl;
    cout << "HP: " << mon.monsterhp_v << " / 50" << endl;
    cout << "Damage: " <<  mon.monsterattack_v << endl;
    cout << "Defense: " << mon.monsterdefense_v << endl;
    cout << endl;

}

void Redraw_f(int playerhand[], int playerdeck[]) {
    bool isoverlapped = true;
    random_device rd;
  
    while (isoverlapped) {
        minstd_rand gen(rd());
        uniform_int_distribution<int> dis(1, 20);
        int redraw = dis(gen);
        int i = 1;
        if (playerdeck[redraw] == i){ // if the randomly generated card is not equal to the card that the user has previously picked, it assigns the card to the user's deck. Same for the monster.
            playerhand[0] = redraw;
            playerdeck[redraw] = 0;
            isoverlapped = false;
            }
        else isoverlapped =true; // After the card is assigned it exits the loop, otherwise return back to the loop, until a non-repeated card is assigned.
        }
    }

void ItemList_f(int &current_weapon, int &current_armor, Players &user){
    for(int i = 0; i <user.playerequipment_v.size(); i++){
        if(user.playerequipment_v[i]/100 == 1){
            int weapon = user.playerequipment_v[i];
            current_weapon += (weapon%100);
        }
        else if(user.playerequipment_v[i]/100 == 2){
            int armor = user.playerequipment_v[i];
            current_armor += (armor%200);
        }
    }

}

void Sort_f(int hands[]){ // This function sorts the hands of cards in the ascending order. This is a necessary process for the monster to pick the card. The excludes the lowest number card and randomly picks one the card with the highest and second highest number.
    int i , j, temp;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(hands[i]>hands[j]) // sorts in ascending order
            {
                temp = hands[i];
                hands[i]=hands[j];
                hands[j]=temp;
            }
        }
    }
}
