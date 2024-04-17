#include <iostream>
#include <raylib.h>
#include "include/model.h"
#include "include/cursor.h"
#include <string>

using std::cout;
using std::endl;
using namespace tedit;


int main()
{
    tedit::TEModel model = tedit::TEModel::getInstance();
    Cursor *cursor = new Cursor(50, 50);
    model.setCursor(cursor);
    InitWindow(500, 500, "tedit");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        cursor->draw();
        for (Character chr : model.buffer) {
            std::string s = "";
            s += chr.chr;
            DrawText(s.c_str(), chr.x, chr.y, 18, RAYWHITE);
        }

        int key = GetKeyPressed();
        if (key != 0)
            cout << key << endl;
        cursor->update(model.parse(key));
        /*
        if (key != 0)
        {

            if (key == 259)
            {
                if (!model.buffer.empty()) {
                    cursor.x -= 15;
                    model.buffer.pop_back();
                }
                
            } else {
            model.type((char)key, cursor);
            cout << "Type: " << key << endl;
            cursor.x += 15;
            if (cursor.x >= 450)
            {
                cursor.x = 50;
                cursor.y += 30;
            }
            }
        }
        */

        EndDrawing();
    }
    delete cursor;
    CloseWindow();
}