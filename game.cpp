#include "game.h"
#include "players.h"
#include "aliens.h"
#include "bart.h"
#include "mikail.h"
#include "osman.h"

#include <QPainter>
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

Game::~Game()
{
    ;
}

void Game::paintEvent(QPaintEvent *event) /* 56 : GUI */
{
    QPainter painter(this);

    if (GameOver)
    {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Game Over");
        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Game Over");

        if (NewHigh == true)
        {
            int textWidth2 = fm.width("New High Score: ");
            int textWidth3 = fm.width(QString::number(HighScore));

            painter.drawText(-textWidth2/2, 20, "New High Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(HighScore));
        }
        else
        {
            int textWidth2 = fm.width("Last Score: ");
            int textWidth3 = fm.width(QString::number(Score));

            painter.drawText(-textWidth2/2, 20, "Last Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(Score));

            int textWidth4 = fm.width("High Score: ");
            int textWidth5 = fm.width(QString::number(HighScore));

            painter.drawText(-textWidth4/2, 60, "High Score: ");
            painter.drawText(-textWidth5/2, 80, QString::number(HighScore));
        }
    }
    else
    {
        QFont font("Courier", 10, QFont::DemiBold);
        int w = width();

        painter.setFont(font);
        painter.drawText(QPoint(w/2-35, 10), "Score: " + QString::number(Score));

    }
}

/*void Game::KeyPressEvent(QKeyEvent *event)
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
*/
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
