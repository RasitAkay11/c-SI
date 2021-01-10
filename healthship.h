#ifndef HEALTHSHIP_H
#define HEALTHSHIP_H
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Healthship: Enemy{//2. useful class, 4. inheritance, 37. usefill Qt class
    Q_OBJECT
public:
    Healthship(QGraphicsItem * parent = 0); //12. specific constructor.
public slots://49. useful usage of signals/slots
    void move(); //16. useful member function.
};

#endif // HEALTHSHIP_H
