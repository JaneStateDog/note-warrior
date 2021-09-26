#ifndef NOTE_WARRIOR_GAME_H
#define NOTE_WARRIOR_GAME_H

#include "raylib.h"

#include "../Octagon/Octagon.h"


class Game {
private:
    Octagon octagon;

public:
    explicit Game(Vector2 winSize);


    void Update();
    void Render();
};


#endif //NOTE_WARRIOR_GAME_H
