#include "health.h"
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
}

int Health::getHealth()
{
    return health;
}
