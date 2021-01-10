#include "score.h"
#include <QFont>
using namespace SpaceInvaderz;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score to zero
    score = 0;
    // draw score
    setPlainText(QString("Score : " + QString::number(score)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times,16"));
}

void Score::setScore()
{
    score++;
    setPlainText(QString("Score : " + QString::number(score))); //updating text
}
