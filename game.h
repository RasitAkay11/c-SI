#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "players.h"
#include "aliens.h"

#include <QtGui/QKeyEvent>
#include <QWidget>

class Game : public QWidget{
    Q_OBJECT
public:
  Game(QWidget *parent = nullptr);
  ~Game();

protected:
    void paintEvent(QPaintEvent *event);
    //void KeyPressEvent(QKeyEvent *Event);
    void StartGame();
    void StartGame(int);
    void PauseGame();
    void StopGame();
private:
    int x;
    int Score;
    int HighScore;
    int timer;
    bool NewHigh;
    bool GameStarted;
    bool GameOver;
    bool GamePaused;
    bool paused;
    Aliens *aliens;
    Player *player;
};

#endif // GAME_H
