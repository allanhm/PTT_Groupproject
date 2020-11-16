#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
#include "characterinfo.h"
#include "load.h"

using namespace std;

bool profile_creation(int button, Players &user) {
    string name_;
    bool check = true;
    while (check){
        switch(button){
            case 1:
                while(true){
                    cout << "Create new profile" << endl;
                    cout << "Enter your name: ";
                    cin >> name_;
                    user.playername_v = name_;
                    name_ += ".txt"; // input the character name
                    ifstream file(name_); //check if the file with the same name exists
                    if (file) { //if so iterate again
                        cout << "Name already exists. Please enter a different name." << endl;
                        }
                    else {
                        ofstream write(name_); // make a new file if the character name is not exist
                        write.close();
                        cout << "Welcome to Deck Dungeon!";
                        check = false;
                        break;
                    }
                }
                break;
            case 2: // Load the file
                while (true) {
                    cout << "Enter your name: " << endl;
                    cin >> name_;
                    string users = name_;
                    name_ += ".txt";
                    ifstream read; // to check its existence
                    read.open(name_);
                    if (read.fail()) { // if one cannot find it ask to type again
                        cout << "Your name does not exist. Type your name again" << endl;
                    }
                    else { // if the program find it it will load the file
                        load_f(user);
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

        }
        }
        return false;
    }
