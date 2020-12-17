#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score to zero
    score = 0;

    // draw score
    setPlainText(QString("Score : " + QString::number(score)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times,16"));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score : " + QString::number(score))); //updating text
}

int Score::getScore()
{
    return score;
}
