#include "aliens.h"
#include <iostream>

Aliens::Aliens(int x, int y) : destroyed(false){
    ;
}

Aliens::~Aliens()
{
    std::cout << ("Alien destroyed\n"); /* 32 : Container Class */
}

bool Aliens::isDestroyed()
{
    return destroyed;
}

void Aliens::setDestroyed(bool destr)
{
    destroyed = destr;
}


QImage &Aliens::getImage()
{
    return image;
}
