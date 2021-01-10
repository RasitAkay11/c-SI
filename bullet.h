#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

namespace SpaceInvaderz{ //23. everything in one of more selfmade namespaces
class Bullet: public QObject, public QGraphicsPixmapItem{//2. useful class, 6. meerdere inheritance, 37. usefull Qt class
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = nullptr); //12. specific constructor. 46. Useful usage of nullptr
    bool enemyhit; //30. Atleast 4 useful bool.
    bool friendhit; //30. Atleast 4 useful bool.
private  slots: //49. useful usage of signals/slots
    void move(); //16. useful member function.
private:
    QMediaPlayer * bulletsound;
    QMediaPlayer * invaderkilled;
    QMediaPlayer * friendkilled;
};
}


#endif // BULLET_H
