#ifndef NOTE_WARRIOR_CONTROLSCONTROLLER_H
#define NOTE_WARRIOR_CONTROLSCONTROLLER_H

#include "raylib.h"


namespace Controls {
    extern bool KeyUp;
    extern bool KeyDown;
    extern bool KeyLeft;
    extern bool KeyRight;

    extern bool KeyUpPressed;
    extern bool KeyDownPressed;
    extern bool KeyLeftPressed;
    extern bool KeyRightPressed;

    extern bool KeyEnterPressed;


    void Update();
}


#endif //NOTE_WARRIOR_CONTROLSCONTROLLER_H
