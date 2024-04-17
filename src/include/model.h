#ifndef MODEL_H_
#define MODEL_H_

#include "cursor.h"
#include "character.h"
#include <vector>

namespace tedit {

    class TEModel
    {
        double zoom;
        int tabAmount;
        TEModel();
        void tab();
        void deleteChar();
        Cursor *cursor;
    public:
        ~TEModel();
        std::vector<Character> buffer;
        static TEModel& getInstance();
        void setCursor(Cursor*);
        void type(char, const Cursor&);
        void readInput(Cursor&);
        Action parse(int);
    };

}

#endif