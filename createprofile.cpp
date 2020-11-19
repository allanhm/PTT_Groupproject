#include <iostream>
#include <fstream>
#include <string>
#include "createprofile.h"
#include "characterinfo.h"
#include "load.h"
#include "Battle.h"

using namespace std;

bool profile_creation(char button, Players &user) {
    string name_; // character name
    bool check = true;
        switch(button){
            case '1': // When the user decides to create a new character
                while(true){
                    cout << endl;
                    cout << "-----Create a new profile-----" << endl;
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
                        StatusAfterBPlyaer_f(0, 0, user);
                        check = false;
                        break;
                    }
                }
                break;
                
            case '2': // When the user selects to use the previously created profile, load the data.
                while (true) {
                    cout << "Enter your name: ";
                    cin >> name_;
                    string users = name_;
                    name_ += ".txt";
                    ifstream read; // to check its existence
                    read.open(name_);
                    if (read.fail()) { // if one cannot find it ask to type again
                        cout << "Your name does not exist. Type your name again" << endl;
                    }
                    else { // if the program find it it will load the file
                        user.playername_v = users;
                        load_f(user);
                        cout << "Welcome back" << endl <<endl;
                        read.close();
                        check = false;
                        break;
                    }
                }
                break;
                
            case '3':
                cout << "Bye Bye!" <<endl;
                cout << "The game is terminated";
                exit(1);
            default:
                cout << "Choose again!"<< endl;
                return check;
            }
    
        return check;
    }
