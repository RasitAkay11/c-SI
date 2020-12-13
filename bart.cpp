#include "bart.h"

Bart::Bart(int x,int y) : Aliens(x,y)
{
    image.load(":/resources/bart.jpg");
}

int Bart::gotShot(int oldScore){
    return 3;
}
