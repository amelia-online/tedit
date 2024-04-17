#ifndef CURSOR_H_
#define CURSOR_H_

#include "drawable.h"

namespace tedit {

class Cursor : Drawable 
{
    bool isVisisble;
    int frameCounter;
    const int expire = 3000;
    void move(int, int);
    void moveX(int);
    void moveY(int);
public:
    int x, y;
    Cursor(int, int);
    Cursor(const Cursor&);
    Cursor& operator=(Cursor);
    virtual void draw();
    virtual void update(Action);
};

}

#endif