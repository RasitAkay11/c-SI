#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>

class Bullet{
public:
    Bullet(int, int);
    ~Bullet();

public:
    void ResetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

protected:
    QImage image;
    QRect rect;

private:
    unsigned char points;
    bool destroyed;
};


#endif // BULLET_H
