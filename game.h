#ifndef GAME_H
#define GAME_H
#include <iostream>
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
    int Lives;
    bool GameStarted;
    bool GameOver;
    bool GamePaused;
};

#endif // GAME_H
