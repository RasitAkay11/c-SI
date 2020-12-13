#ifndef players_H
#define players_H

#include <QGraphicsItem>
#include <QImage>
#include <QRect>
#include <stdio.h>
#include <stdlib.h>
#include <list>

class Player: public QGraphicsItem{
public:
    Player(int, int);
    ~Player(); /* 12 : Deconstructor */

public:
    int Lives;
    void keyPressEvent(QKeyEvent * event);
    QRect getRect();
    void setRect(int, int, int, int);
    QImage image;
    int x, y;

    void Shoot();


  private:
    unsigned int numQueuedSegments;
};



#endif // player_H
