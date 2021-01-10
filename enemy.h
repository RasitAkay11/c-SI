#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

namespace SpaceInvaderz{//23. everything in one of more selfmade namespaces
class Enemy: public QObject, public QGraphicsPixmapItem{//2. useful class, 6. meerdere inheritance, 37. usefill Qt class 7. Base class(van vriend)
    Q_OBJECT
public:
    Enemy(); //11. Default constructor. 46. Useful usage of nullptr
protected slots://49. useful usage of signals/slots //20. Correct protection
    void move(); //16. useful member function. 39. useful function overriding
};
}

#endif // ENEMY_H
