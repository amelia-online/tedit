#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "character.h"

class Drawable
{
public:
    virtual void draw() = 0;
    virtual void update(tedit::Action) = 0;
};

#endif