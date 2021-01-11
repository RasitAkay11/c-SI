#ifndef players_H
#define players_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "health.h"
#include "score.h"
#include "enemy.h"
#include "vriend.h"
#include <QObject>
#include <QMediaPlayer>

namespace SpaceInvaderz
{//23. everything in one of more selfmade namespaces
class Player:public QObject, public QGraphicsPixmapItem{//2. useful class, 6. meerdere inheritance, 37. usefill Qt class
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = nullptr); //12. specific constructor. 46. Useful usage of nullptr
    ~Player(); //14. Atleast 2 deconstructors.
    void keyPressEvent(QKeyEvent * event); //45. useful recursive function
public slots://49. useful usage of signals/slots
    void spawnE(); //16. useful member function.
    void spawnF(); //16. useful member function.
private:
    QMediaPlayer * bulletsound;
};
}


#endif // player_H
