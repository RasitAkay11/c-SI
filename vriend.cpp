#include "vriend.h"
#include "game.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
using namespace SpaceInvaderz;
extern Game * game;

Vriend::Vriend()
{
    // set random position
    unsigned __int16 rndmnr = rand() % 700;
    setPos(rndmnr,0);

    //draw the player
    setPixmap(QPixmap(":/images/images/friend.png")); //47.useful (modern) usage of file I/O
    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer(); //connect. 32. Dynamic memory allocation(new)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//49. useful usage of signals/slots

    timer->start(50);
}

void Vriend::move()
{
    //move friend down
    setPos(x(), y()+4);

    //remove friend after its off the screen to reduce memory. 26. Memory deleting
    if(pos().y() > 600)
    {
        for(unsigned __int8 i = 0; i < 2 ; i++) //26. unsigned char = unsigned int8
        {
        game->health->decreaseHealth(); //Player must shoot vriend down, or his health will decrease twice instead of increase once.
        }
        scene()->removeItem(this); //15. useful usage of this
        delete this; //15. useful usage of this. 33. Dynamic memory removing(delete)
        qDebug() << "Friend removed to reduce memory";
    }
}
