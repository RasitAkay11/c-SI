#include "enemy.h"
#include "game.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
using namespace SpaceInvaderz;
extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    // set random position
    unsigned __int16 rndmnr = rand() % 700; //27. Using best suited type everywhere
    setPos(rndmnr,0);

    //draw the player
    setPixmap(QPixmap(":/images/images/alien.png")); //47.useful (modern) usage of file I/O
    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer(); //connect. 32. Dynamic memory allocation(new)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//49. useful usage of signals/slots

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+6);

    //remove enemy after its off the screen to reduce memory. 26. Memory deleting
    if(pos().y() > 600)
    {
        //decrease health
        game->health->decreaseHealth();
        scene()->removeItem(this); //15. useful usage of this
        delete this; //15. useful usage of this. 33. Dynamic memory removing(delete)
        qDebug() << "Enemy removed to reduce memory";
    }
}
