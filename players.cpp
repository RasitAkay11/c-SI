#include "players.h"
#include "vriend.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
using namespace SpaceInvaderz;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) //linking an image and sound to the player
{
    setPixmap(QPixmap(":/images/images/player.png"));//47.useful (modern) usage of file I/O
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/shoot.wav"));//47.useful (modern) usage of file I/O
}

Player::~Player()
{
    delete this;
}

void Player::keyPressEvent(QKeyEvent *event) //making the player move
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0){
            qDebug() << "Player moving left";
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
        {
            qDebug() << "Player moving right";
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        qDebug() << "Player shooting";
        Bullet * bullet = new Bullet(); //32. Dynamic memory allocation(new)
        bullet->setPos(x()+40,y());
        bulletsound->play();
        scene() -> addItem(bullet);
    }
}

void Player::spawnE(){// create an enemy
    Enemy * enemy = new Enemy(); //32. Dynamic memory allocation(new)
    scene()->addItem(enemy);
}

void Player::spawnF() //create a friend
{
    Vriend * vriend = new Vriend();
    scene()->addItem(vriend);
}
