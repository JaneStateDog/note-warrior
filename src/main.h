#ifndef NOTE_WARRIOR_MAIN_H
#define NOTE_WARRIOR_MAIN_H

#include "raylib.h"

#include "States/MainMenu/MainMenu.h"
//#include "States/Game/Game.h"
#include "States/Editor/Editor.h"


class MainMenu;
//class Game;
class Editor;


extern Vector2 screenSize;
extern Camera2D camera;
extern Camera2D UICamera;


namespace States {
    enum states {
        MainMenu,
        Game,
        Editor
    };
}

extern States::states state;


extern MainMenu mainMenu;
//extern Game game;
extern Editor editor;


extern int standardOctagonSize;


#endif //NOTE_WARRIOR_MAIN_H