#ifndef players_H
#define players_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
       void spawn();
private:
    QMediaPlayer * bulletsound;
};



#endif // player_H
