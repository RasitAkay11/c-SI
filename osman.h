#ifndef OSMAN_H
#define OSMAN_H
#include "aliens.h"

class Osman : public Aliens
{
public:
    Osman();
    Osman(int, int);

    int gotShot(int oldScore);
};

#endif // OSMAN_H
