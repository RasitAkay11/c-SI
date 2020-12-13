#ifndef MIKAIL_H
#define MIKAIL_H
#include "aliens.h"

class Mikail : public Aliens
{
public:
    Mikail();
    Mikail(int, int);

    int gotShot(int oldScore);
};

#endif // MIKAIL_H
