#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
using namespace SpaceInvaderz;
extern Game * game; //external global object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) //6. useful and correct multiple inheritance
{
    setPixmap(QPixmap(":/images/images/bullet.png")); //47.useful (modern) usage of file I/O
    QTimer * timer = new QTimer(); //connect
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//49. useful usage of signals/slots
    timer->start(50);
}


void Bullet::move()
{
    // check if bullet collides with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(unsigned __int8 i = 0, n = colliding_items.size(); i<n; i++)//26. unsigned char = unsigned int8
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase the score
            game->score->setScore();

            //remove them both. 26. Memory deleting
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            invaderkilled = new QMediaPlayer(); //32. Dynamic memory allocation(new)
            invaderkilled->setMedia(QUrl("qrc:/sounds/sounds/invaderkilled.wav")); //47.useful (modern) usage of file I/O
            invaderkilled->play();
            qDebug() << "Invader killed!";
            enemyhit = true;

            //mem deleting. 26. Memory deleting
            delete colliding_items[i];
            delete this; //33. Dynamic memory removing(delete)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Vriend))
        {
            //increase the score
            game->health->increaseHealth();

            //remove them both. 26. Memory deleting
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            friendkilled = new QMediaPlayer(); //32. Dynamic memory allocation(new)
            friendkilled->setMedia(QUrl("qrc:/sounds/sounds/explosion.wav")); //47.useful (modern) usage of file I/O
            friendkilled->play();
            qDebug() << "Health increased!";
            friendhit = true;

            //mem deleting. 26. Memory deleting
            delete colliding_items[i];
            delete this; //33. Dynamic memory removing(delete)
            return;
        }
    }

    //move bullet up
    setPos(x(), y()-15);

    //remove bullet after its off the screen to reduce memor. //26. Memory deleting
    if(pos().y() < 0)
    {
        scene()->removeItem(this);//15. useful usage of this
        delete this; //33. Dynamic memory removing(delete)
        qDebug() << "Bullet removed to reduce memory.";
    }
}
