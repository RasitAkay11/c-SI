#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "players.h"
#include "score.h"
#include "health.h"
#include "enemy.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent = 0);

    bool gamestarted;
    bool gameover;

    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Score * score;
    Health * health;
};



#endif // GAME_H
