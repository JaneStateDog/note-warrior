#include "Polygon.h"

#include <cmath>

#include "../Functions/Functions.h"
#include "../ControlsController/ControlsController.h"
#include "../main.h"


Polygon::Polygon(Vector2 inPos, int inSize, int inSides)
    : pos(inPos), size(inSize), sides(inSides)
{}


void Polygon::SetPos(Vector2 inPos) { pos = inPos; }
Vector2 Polygon::GetPos() { return pos; }

void Polygon::SetSize(int inSize) { size = inSize; }
int Polygon::GetSize() const { return size; }

int Polygon::GetSelectedSide() const { return selSide; }

int Polygon::GetSides() const { return sides; }

void Polygon::SetFlashing(bool inFlashing) { flashing = inFlashing; }

int Polygon::GetSideOfMouse() const { return sideOfMouse; }
float Polygon::GetDistanceOfMouse() const { return distanceOfMouse; }


void Polygon::Update() {
    if (moveFlipper) {
        if (Controls::KeyLeft) { selSide--; }
        else if (Controls::KeyRight) { selSide++; }

        moveFlipper = false;
    } else { moveFlipper = true; }

    if (selSide < 0) { selSide = sides - 1; }
    else if (selSide > sides - 1) { selSide = 0; }


    if (flashing) {
        flashCounter++;

        if (flashCounter >= 5) {
            flashing = false;
            flashCounter = 0;
        }
    }


    //Get side of mouse and distance of mouse
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera);
    float initAngle = 360.f / (float)sides;


    double roughDegrees = std::atan2(mousePos.y - pos.y, mousePos.x - pos.x) * (180.f / M_PI);
    if (roughDegrees < 0) { roughDegrees += 360; }
    sideOfMouse = (int)(roughDegrees / initAngle);


    Vector2 t1 = Lengthdir((float)(initAngle * (float)sideOfMouse) + (initAngle / 2), float(size));
    t1 = {pos.x + t1.x, pos.y + t1.y};

    distanceOfMouse = (float)sqrt(pow((t1.x - mousePos.x), 2) + pow((t1.y - mousePos.y) , 2));

    selSide = sideOfMouse;
}

void Polygon::Render(bool guideLines) const {
    int lastX;
    int lastY;

    Vector2 t1 = Lengthdir(0, (float) size);
    int newX = (int)t1.x;
    int newY = (int)t1.y;

    for (int i = 1; i <= sides; i++) {
        lastX = newX;
        lastY = newY;

        Vector2 t2 = Lengthdir((float)((360.f / (float)sides) * (float)i), (float)size);
        newX = (int)t2.x;
        newY = (int)t2.y;

        Color color = WHITE;

        if (selSide + 1 == i) { color = GREEN; }
        else if (flashing) { color = RED; }

        DrawLine((int)pos.x + lastX, (int)pos.y + lastY,
                    (int)pos.x + newX, (int)pos.y + newY,
                        color);

        if (guideLines) {
            bool flipper = false;

            Vector2 t3 = Lengthdir((float)((360.f / (float)sides) * (float)i) - (360.f / (float)sides), editor.GetScrollSpeed() * 2);
            Vector2 lastPos = {pos.x + (float)lastX, pos.y + (float)lastY};

            for (int b = 0; b < (int)(screenSize.x / camera.zoom); b++) {
                Color color2;
                if (flipper) { color2 = WHITE; } else { color2 = GRAY; }
                DrawLine((int)lastPos.x, (int)lastPos.y,
                            (int)(lastPos.x + t3.x), (int)(lastPos.y + t3.y),
                            color2);

                flipper = !flipper;
                lastPos = {lastPos.x+ t3.x, lastPos.y + t3.y};
            }
        }
    }
}