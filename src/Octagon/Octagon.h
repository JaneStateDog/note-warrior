#ifndef NOTE_WARRIOR_OCTAGON_H
#define NOTE_WARRIOR_OCTAGON_H

#include "raylib.h"


class Octagon {
private:
    Vector2 pos;
    int size;

    int sides;
    int selSide = 0;

    bool moveFlipper = false;

    bool flashing = false;
    int flashCounter = 0;

public:
    Octagon(Vector2 inPos, int inSize, int inSides);


    void SetPos(Vector2 inPos);
    Vector2 GetPos();

    void SetSize(int inSize);
    int GetSize() const;

    int GetSelectedSide() const;

    int GetSides() const;

    void SetFlashing(bool inFlashing);


    void Update();
    void Render(bool editor = false) const;
};


#endif //NOTE_WARRIOR_OCTAGON_H
