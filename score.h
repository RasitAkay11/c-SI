#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

namespace SpaceInvaderz{//23. everything in one of more selfmade namespaces
class Score: public QGraphicsTextItem{//2. useful class, 4. inheritance, 37. usefill Qt class
public:
    Score(QGraphicsItem * parent = nullptr); //12. specific constructor. 46. Useful usage of nullptr
    void setScore(); //19. useful setter.
    unsigned __int16 getScore()           {return score;}   ; //19. useful getter. 44. Correct usage of inline function. 27. Best suited type everywhere(0 to 65.535)
private:
    unsigned __int16 score; //18. useful member variabel
};
}

#endif // SCORE_H
