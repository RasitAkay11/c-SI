#ifndef BART_H
#define BART_H
#include "aliens.h"

class Bart : public Aliens
{
public:
    Bart();
    Bart(int, int);

    int gotShot(int oldScore);
};

#endif // BART_H
