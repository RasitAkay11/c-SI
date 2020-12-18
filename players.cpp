#include "players.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/player.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/shoot.wav"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            qDebug() << "Player moving left";
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800){
            qDebug() << "Player moving right";
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space){
        qDebug() << "Player shooting";
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+40,y());
        bulletsound->play();
        scene() -> addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
