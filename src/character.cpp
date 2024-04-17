#include "include/character.h"
#include <raylib.h>

using namespace tedit;

Character::Character(int x, int y, int fontsize, char chr) : x(x), y(y), fontsize(fontsize), chr(chr) {;}

Character::Character(int x, int y, char chr) : x(x), y(y), chr(chr)
{
    fontsize = GetFontDefault().baseSize;
}

Character Character::next()
{

}