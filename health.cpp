#include "health.h"
#include "game.h"
#include <QApplication>
#include <QFont>


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score to zero
    health = 3;

    // draw score
    setPlainText(QString("Health: " + QString::number(health)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times,16"));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: " + QString::number(health))); //updating text
    if(health < 1){
        QApplication::quit();
    };
}

int Health::getHealth()
{
    return health;
}
