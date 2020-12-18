#include "enemy.h"
#include "game.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int rndmnr = rand() % 700;
    setPos(rndmnr,0);

    //draw the player
    setPixmap(QPixmap(":/images/images/alien.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer(); //connect
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+5);

    //remove enemy after its off the screen to reduce memory
    if(pos().y() > 600){
        //decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy removed to reduce memory";
    }
}
