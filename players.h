#ifndef players_H
#define players_H
#include <QImage>
#include <QRect>
#include <stdio.h>
#include <stdlib.h>
#include <list>

class Player{
public:
    Player(int, int);
    ~Player(); /* 12 : Deconstructor */

public:
    int Lives;
    enum Direction{UP, DOWN, LEFT, RIGHT};
    struct Segment /* 48 : Sruct */
    {
        Segment(QImage image, QRect rect, int x, int y)
                    : image(image)
                    , rect(rect)
                    , x(x)
                    , y(y)
                    { }
        QImage image;
        QRect rect;
        int x, y;

    };

    Direction dir;
    QImage image;
    typedef std::list<Segment> Segmentlist;
    Segmentlist segments;
    int x, y;

    void Move();
    void Shoot();

    const Segment & ship() const{
        return segments.front();
    }
};



#endif // player_H
