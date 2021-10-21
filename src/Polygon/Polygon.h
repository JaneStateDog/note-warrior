#ifndef NOTE_WARRIOR_POLYGON_H
#define NOTE_WARRIOR_POLYGON_H

#include "raylib.h"


class Polygon {
private:
    Vector2 pos;
    int size;

    int sides;
    int selSide = 0;

    bool moveFlipper = false;

    bool flashing = false;
    int flashCounter = 0;

    int sideOfMouse = 0;
    float distanceOfMouse = 0;

public:
    Polygon(Vector2 inPos, int inSize, int inSides);


    void SetPos(Vector2 inPos);
    Vector2 GetPos();

    void SetSize(int inSize);
    int GetSize() const;

    int GetSelectedSide() const;

    int GetSides() const;

    void SetFlashing(bool inFlashing);

    int GetSideOfMouse() const;
    float GetDistanceOfMouse() const;


    void Update();
    void Render(bool editor = false) const;
};


#endif //NOTE_WARRIOR_POLYGON_H
