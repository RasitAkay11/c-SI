#include "game.h"
#include "players.h"
#include <QtGui/QKeyEvent>

Game::Game(QWidget *parent) : QWidget(parent){
    x = 0;
    Score = 0;
    HighScore = 0;
    Lives = 3;
    GamePaused = false;
    GameStarted = false;
    GameOver = false;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:///Key_Q:
         Player->dir = Player::LEFT;
       break;
    case Qt::Key_Right: ///Key_D:
          Player->dir = Player::RIGHT;
        break;
        break;
    case Qt::Key_P:
          PauseGame();
        break;
    case Qt::Key_Space:
          StartGame();
        break;
    case Qt::Key_Escape:
          qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
