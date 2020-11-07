#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "createprofile.h"
using namespace std;

void createprofile() {
    bool new_game = start();
    string name_;
    while (new_game == 1) {
        cout << "Create new profile" << endl;
        cout << "Enter your name: " << endl;
        cin >> name_;
        name_ = name_ + ".txt";
        ifstream file(name_.c_str()); //check if the file with the same name exists
        if (file) {
            cout << "Name already exists. Please enter a different name." << endl;
        }
        else {
            ofstream write;
            write.open(name_.c_str());
            /// 게임 스타트?
        }
    }

    while (new_game == 0) {
        cout << "Enter your name: " << endl;
        cin >> name_;
        name_ = name_ + ".txt";
        ifstream read;
        read.open(name_.c_str())
        if (name_.fail()) {
            cout << "Your name does not exist. Type your name again" << endl;
        }
        else {
            cout << "Welcome back" << endl;
            read.close();
        }
    }

}
