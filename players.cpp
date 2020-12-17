#include "players.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            qDebug() << "key left was pressed";
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800){
            qDebug() << "key Right was pressed";
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space){
        qDebug() << "key Space was pressed";
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene() -> addItem(bullet);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
