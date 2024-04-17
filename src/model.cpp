#include "include/model.h"
#include <raylib.h>
#include "include/character.h"

using namespace tedit;

TEModel::TEModel() : zoom(1.0), tabAmount(2) {}

TEModel& TEModel::getInstance()
{
    static TEModel m;
    return m;
}

TEModel::~TEModel()
{
    
}

void TEModel::tab()
{
}

void TEModel::type(char chr, const Cursor& cursor)
{
   Character c(cursor.x, cursor.y, chr);
   buffer.push_back(c);
}

void TEModel::setCursor(Cursor *ptr)
{
    cursor = ptr;
}

Action TEModel::parse(int input)
{
    switch (input)
    {
        case 258:
            tab();
            return Tab;

        case 259:
            return Delete;
        
        case 257:
            return Return;

        case 280:
            return CapsLock;

        case 265:
            return ArrowUp;

        case 264:
            return ArrowDown;

        case 263:
            return ArrowLeft;

        case 262:
            return ArrowRight;

        default:
            return None;
    }
    
    return Ascii;
}

void TEModel::readInput(Cursor& cursor)
{
    int key = GetKeyPressed();
    switch (key)
    {
        default:
            if (cursor.x >= 500)
            {
                cursor.x = 50;
                cursor.y += 30;
                return;
            }
            cursor.x += 15;
            break;
    }
}