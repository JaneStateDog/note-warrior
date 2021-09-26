#include "ControlsController.h"


namespace Controls {
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyLeft = false;
    bool KeyRight = false;

    bool KeyUpPressed = false;
    bool KeyDownPressed = false;
    bool KeyLeftPressed = false;
    bool KeyRightPressed = false;

    bool KeyEnterPressed = false;


    void Update() {
        KeyUp = (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP));
        KeyDown = (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN));
        KeyLeft = (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT));
        KeyRight = (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT));

        KeyUpPressed = (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP));
        KeyDownPressed = (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN));
        KeyLeftPressed = (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT));
        KeyRightPressed = (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT));

        KeyEnterPressed = (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE));
    }
}