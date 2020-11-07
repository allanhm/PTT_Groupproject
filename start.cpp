#include <iostream>
#include "start.h"
using namespace std;

bool start() {
    int select = 0;
    bool new_game = false;
    cout << "Select" << endl;
    cout << "1. New game" << endl;
    cout << "2. Load game" << endl;
    cin >> select;
    if (select == 1) {
        new_game = true;
    }
    
    else if (select == 2) {
        new_game = false;
    }

    return new_game;
}




