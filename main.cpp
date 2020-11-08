#include <iostream>
#include "windows.h"
using namespace std;

char Map [20][20] = {
    "###################",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#         W       #",
    "###################"
};

bool endgame = false;
int gamespeed = 400;

int man(){

    while(endgame == false){
        system("cls");
        for(int y = 0; y < 20; y++){
            cout << Map[y];
        }
    }
    return 0;
}
