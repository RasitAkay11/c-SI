#include "players.h"
#include <iostream>
using namespace std;


Player::Players{
    image.load(":/resources/player.png");
};

void Player::Move(){
    QRect rect;
    rect = image.rect();
    int y;
    switch (Direction) {
        case Player::LEFT:
            y -=7;
        break;
        case Player::RIGHT:
            y +=7;
        break;
    }
}
