#ifndef CHARACTER_H_
#define CHARACTER_H_

namespace tedit {
    class Character 
    {
        static int lastX;
        static int lastY;
    public:
        static Character next();
        int x, y;
        int fontsize;
        char chr;
        Character(int, int, int, char);
        Character(int, int, char);
    };

    enum Action
    {
        Delete = 0,
        Space,
        Tab,
        ArrowUp,
        ArrowDown,
        ArrowLeft,
        ArrowRight,
        CapsLock,
        Return,
        Ascii,
        Shift,
        None,
        Control,
        Super,
        Option,
    };
}

#endif