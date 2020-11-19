#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "characterinfo.h"
#include "createprofile.h"
using namespace std;
void save_f(Players &user) { // saves the current progress of the user from the point that the user saved and quit.
    ofstream write;
    string filename = user.playername_v + ".txt"; // The name of the txt file is the user's name.
    write.open(filename,ios::out); 
    
    if ( write.fail() ) // when cannot open the file 
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    
    write << user.playerhp_v << endl; // Store information in the file.
    write << user.playerround_v << endl;
    write << user.playerattack_v << endl;
    write << user.playerdefense_v << endl;
    
    for (auto itr = user.playerequipment_v.begin(); itr != user.playerequipment_v.end(); ++itr)
    {
        write << *itr << endl;
    }
    
    write.close();

    cout << "Save successfully complete! Bye Bye!" << endl;
    exit(1);
}
