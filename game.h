#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "players.h"
#include "vriend.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "bullet.h"

namespace SpaceInvaderz{//23. everything in one of more selfmade namespaces
class Game: public QGraphicsView{//2. useful class, 4. inheritance, 37. usefill Qt class
    Q_OBJECT
public:
    Game(); //11. default constructor. 46. Useful usage of nullptr
    ~Game(); //14. At least 2 deconstructors

    QGraphicsScene * scene;
    Player * player; //5. OBject composition.
    Enemy * enemy;
    Bullet * bullet;
    Score * score;
    Health * health;
    Vriend * vriend;
    bool startgame;//30. Atleast 4 useful bool.
};
}


#endif // GAME_H
