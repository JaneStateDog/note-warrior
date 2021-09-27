#ifndef NOTE_WARRIOR_CONTROLSCONTROLLER_H
#define NOTE_WARRIOR_CONTROLSCONTROLLER_H


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

    extern bool MouseLeftPressed;
    extern bool MouseRightPressed;

    extern float MouseWheelMovement;

    extern bool F11Pressed;


    void Update();
}


#endif //NOTE_WARRIOR_CONTROLSCONTROLLER_H
