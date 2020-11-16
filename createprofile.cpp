#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
#include "characterinfo.h"
using namespace std;

bool profile_creation(int button, Players &user) {
    string name_;
    bool check = true;
    while (check){
        switch(button){
            case 1:
                while(true){
                    cout << "Create new profile" << endl;
                    cout << "Enter your name: " << endl;
                    cin >> name_;
                    name_ += ".txt"; // input the character name
                    ifstream file(name_); //check if the file with the same name exists
                    if (file) {
                        cout << "Name already exists. Please enter a different name." << endl;
                        }
                    else {
                        file.open(name_);
                        check = false;
                        break;
                    }
                }
                break;
            case 2:
                while (true) {
                    cout << "Enter your name: " << endl;
                    cin >> name_;
                    name_ += ".txt";
                    ifstream read;
                    read.open(name_);
                    if (read.fail()) {
                        cout << "Your name does not exist. Type your name again" << endl;
                    }
                    else {
                        cout << "Welcome back" << endl;
                        read.close();
                        check = false;
                        break;
                    }
                }
                break;
            case 3:
                cout << "Bye Bye!" <<endl;
                cout << "The game is terminated";
                exit(1);
                break;
            default:
                cout << "Unavailabe option! Please choose again";
                break;

        }
        }
        return false;
    }

