#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; //external global object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/bullet.png"));

    QTimer * timer = new QTimer(); //connect
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // check if bullet collides with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            invaderkilled = new QMediaPlayer();
            invaderkilled->setMedia(QUrl("qrc:/sounds/sounds/invaderkilled.wav"));
            invaderkilled->play();
            qDebug() << "Invader killed!";

            //mem deleting
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(), y()-15);

    //remove bullet after its off the screen to reduce memory
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet removed to reduce memory.";
    }
}
