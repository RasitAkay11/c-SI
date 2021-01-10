#include "health.h"
#include "game.h"
#include <windows.h>
#include <QApplication>
#include <QFont>
using namespace SpaceInvaderz;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    // draw score
    setPlainText(QString("Health: " + QString::number(health)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times,16"));
}

void Health::decreaseHealth()
{
    health--;
    setPlainText(QString("Health: " + QString::number(health))); //updating text
    if(health < 1)
    {
        gameover();
    };
}

void Health::increaseHealth()
{
    health++;
    setPlainText(QString("Health: " + QString::number(health))); //updating text
}

void Health::gameover() //ending the game
{
    gameOver = true;
    qDebug() << "Game over bro.. Window will close in 5 seconds.";
    Sleep(5000);
    QApplication::quit();
}
