#include "osman.h"

Osman::Osman(int x,int y) : Aliens(x,y)
{
    image.load(":/resources/osman.jpg");
}

int Osman::gotShot(int oldScore){
    return 3;
}
