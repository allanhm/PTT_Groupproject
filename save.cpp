#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

#include "characterinfo.h"
using namespace std;
void save_f() {
    ofstream write;
    write.open(name_);
    write << playerhp_v << endl;
    write << playerattack_v << endl;
    write << playerdefense_v << endl;
    for(int i = 0 ; i < 3 ; i++) {
            write << users.playercard_v[i];
        }
    for(int i = 0 ; i < 3 ; i++) {
            write << users.playerequipment_v[i];
        }
    
    write << playerround_v << endl;
    
    write.close();
    
    exit(1)
}
