#include "players.h"
#include <iostream>
#include <QRect>
#include <QDebug>


Player::Player(int x, int y){
    Lives = 3;
    image.load(":/resources/player.png");
    QRect ship;
    ship = image.rect();
    ship.moveTo(x,y);
}

void Player::keyPressEvent(QKeyEvent *event)
{

    qDebug() << "MyRect knows that you pressed a key";
    /*if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        Shoot();
    }*/
}

QRect Player::getRect()
{
    ;
}

void Player::setRect(int, int, int, int)
{
    ;
}

void Player::Shoot(){
    qDebug() << "anan";
}
