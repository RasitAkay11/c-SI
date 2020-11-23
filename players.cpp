#include "players.h"
#include <iostream>
#include <QRect>


Player::Player(int x, int y){
    Lives = 3;
    image.load(":/resources/player.png");
    QRect ship;
    ship = image.rect();
    ship.moveTo(x,y);
}

void Player::Move(){
    QRect rect;
    rect = image.rect();
    int x = ship().x;
    int y = ship().y;
    switch (dir) {
        case Player::DOWN:
            y += 7;
        break;
        case Player::UP:
            y -= 7;
        break;
        case Player::LEFT:
            x -=7;
        break;
        case Player::RIGHT:
            x +=7;
        break;
    }
    rect.moveTo(x, y);
}

void Player::Shoot(){

}
