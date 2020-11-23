#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "players.h"
#include <QtGui/QKeyEvent>
#include <QWidget>

class Game : public QWidget{
    Q_OBJECT
public:
  Game(QWidget *parent = nullptr); /* 14 : useful member function , 44 : NULLPTR */
  ~Game(); /* 12 : Decunstructor */

protected:
    void KeyPressEvent(QKeyEvent *Event);
    void StartGame();
    void StartGame(int);
    void PauseGame();
    void StopGame();
private:
    int x;
    int Score;
    int HighScore;
    int timer;
    bool GameStarted;
    bool GameOver;
    bool GamePaused;
    bool paused;
    Player *player;
};

#endif // GAME_H
