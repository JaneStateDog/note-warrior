#ifndef NOTE_WARRIOR_MAIN_H
#define NOTE_WARRIOR_MAIN_H

#include "raylib.h"

#include "ControlsController/ControlsController.h"
#include "MainMenu/MainMenu.h"
#include "Game/Game.h"


class MainMenu;
class Game;


extern Vector2 winSize;


namespace States {
    enum states {
        MainMenu,
        Game,
        Editor
    };
}

extern States::states state;


extern MainMenu mainMenu;
extern Game game;


#endif //NOTE_WARRIOR_MAIN_H