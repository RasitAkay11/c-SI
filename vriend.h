#ifndef FRIEND_H
#define FRIEND_H
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

namespace SpaceInvaderz
{//23. everything in one of more selfmade namespaces
class Vriend: public Enemy{//2. useful class, 6. inheritance, 37. usefill Qt class
    Q_OBJECT
public:
    Vriend(); //11. default constructor.
private slots://49. useful usage of signals/slots
    void move(); //16. useful member function. 39. useful function overriding
};
}

#endif // FRIEND_H
