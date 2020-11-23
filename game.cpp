#include "game.h"
#include "players.h"
#include <QtGui/QKeyEvent>

#include <QApplication> ///The QApplication class manages the GUI application's control flow and main settings


Game::Game(QWidget *parent) : QWidget(parent){
    x = 0;
    Score = 0;
    HighScore = 0;
    GamePaused = false;
    GameStarted = false;
    GameOver = false;
}

void Game::KeyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:///Key_Q:
         player->dir = Player::LEFT;
       break;
    case Qt::Key_Right: ///Key_D:
          player->dir = Player::RIGHT;
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
    repaint();
}

void Game::StartGame(){
    if(!GameStarted){
        GameOver = false;
        GamePaused = false;
        Score = 0;
        GameStarted = true;
        timer = startTimer(5);
    }
}

void Game::PauseGame(){
    if(paused){
        timer = startTimer(5);
        paused = false;
    } else{
        paused = true;
        killTimer(timer);
    }
}

void Game::StopGame(){
    killTimer(timer);
    GameOver = true;
    if(Score > HighScore){
        HighScore = Score;
    }
    GameStarted = false;
}
