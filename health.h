#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QDebug>

namespace SpaceInvaderz{//23. everything in one of more selfmade namespaces
class Health: public QGraphicsTextItem{//2. useful class, 4. inheritance, 37. usefill Qt class
public:
    Health(QGraphicsItem * parent = nullptr); //12. specific constructor. 46. Useful usage of nullptr
    bool gameOver; //30. Atleast 4 useful bool.
    void gameover(); //16. useful member function.
    void decreaseHealth();
    void increaseHealth();
    unsigned __int8 getHealth() {return health;}; //19. useful getter. 44. correct useage of inline function 27. Best suited type everywhere(0 to 255)
private:
    unsigned __int8 health; //18. useful member variabel
};
}

#endif // HEALTH_H
