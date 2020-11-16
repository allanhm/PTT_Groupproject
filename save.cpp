#include <iostream>
#include <string>
#include <fstream>

#include "characterinfo.h"
#include "createprofile.h"
using namespace std;
void save_f(Players &user) {
    ofstream write;
    string filename = user.playername_v + ".txt";
    write.open(filename);
    write << user.playerhp_v << endl;
    write << user.playerattack_v << endl;
    write << user.playerdefense_v << endl;
    for(int i = 0 ; i < 3 ; i++) {
            write << user.playercard_v[i];
            if (i== 2){
                write <<endl;
            }
        }

    for(int i = 0 ; i < 3 ; i++) {
            write << user.playerequipment_v[i];
            if (i == 2){
                write << endl;
            }
        }
    write << user.playerround_v << endl;
    
    write.close();
    cout << "Save successfully complete! Bye Bye!" << endl;
    exit(1);
}
