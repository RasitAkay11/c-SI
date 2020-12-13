#include "mikail.h"

Mikail::Mikail(int x,int y) : Aliens(x,y)
{
    image.load(":/resources/mikail.jpg");
}

int Mikail::gotShot(int oldScore){
    return 3;
}
