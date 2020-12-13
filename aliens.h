#ifndef ALIENS_H
#define ALIENS_H

#include <QImage>
#include <QRect>

class Aliens{
public:
    Aliens(int,int);
    ~Aliens();
    virtual int gotShot(int OldScore) = 0;

public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QImage & getImage();

protected:
    QImage image;

private:
    unsigned char points;
    bool destroyed;
};

#endif // ALIENS_H
//inheritance -> osman, mikail en bart als alien. osman weak, mikail strong, bart KING
