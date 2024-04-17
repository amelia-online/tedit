#include "include/cursor.h"
#include <iostream>
#include <raylib.h>

using namespace tedit;

Cursor::Cursor(int x, int y) : x(x), y(y), isVisisble(true), frameCounter(0) {;}

Cursor::Cursor(const Cursor& other) : x(other.x), y(other.y), isVisisble(other.isVisisble), frameCounter(other.frameCounter) {;}

Cursor& Cursor::operator=(Cursor other)
{
    std::swap(x, other.x);
    std::swap(y, other.y);
    std::swap(isVisisble, other.isVisisble);
    std::swap(frameCounter, other.frameCounter);
    return *this;
}

void Cursor::draw()
{
    if (isVisisble)
    {
        DrawRectangle(x - 12, y - 12, 12, 25, RAYWHITE);
    }
}

void Cursor::update(Action a)
{
    switch (a)
    {

        case Tab:
            break;

        default:
           break;

    }
     
    if (frameCounter >= expire) 
    {
        isVisisble = !isVisisble;
        frameCounter = 0;
        return;
    }

    frameCounter++;
}