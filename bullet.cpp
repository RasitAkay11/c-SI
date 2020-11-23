#include "bullet.h"

Bullet::Bullet(int x, int y) :  destroyed(false){
    ;
}

bool Bullet::isDestroyed(){
    return destroyed;
}

void Bullet::setDestroyed(bool destr){
    destroyed = destr;
}

QRect Bullet::getRect(){
    return rect;
}

void Bullet::setRect(QRect rct){
    rect = rct;
}

QImage &Bullet::getImage(){
    return image;
}
