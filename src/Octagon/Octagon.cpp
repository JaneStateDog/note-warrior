#include "Octagon.h"

#include "../Functions/Functions.h"
#include "../ControlsController/ControlsController.h"
#include "../main.h"


Octagon::Octagon(Vector2 inPos, int inSize, int inSides)
    : pos(inPos), size(inSize), sides(inSides)
{}


void Octagon::SetPos(Vector2 inPos) { pos = inPos; }
Vector2 Octagon::GetPos() { return pos; }

void Octagon::SetSize(int inSize) { size = inSize; }
int Octagon::GetSize() const { return size; }

int Octagon::GetSelectedSide() const { return selSide; }

int Octagon::GetSides() const { return sides; }

void Octagon::SetFlashing(bool inFlashing) { flashing = inFlashing; }


void Octagon::Update() {
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
}

void Octagon::Render(bool guideLines) const {
    int lastX;
    int lastY;

    Vector2 t1 = Lengthdir(0, (float) size);
    int newX = (int)t1.x;
    int newY = (int)t1.y;

    for (int i = 1; i <= sides; i++) {
        lastX = newX;
        lastY = newY;

        Vector2 t2 = Lengthdir((float) ((360.f / (float)sides) * (float)i), (float)size);
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

            Vector2 t3 = Lengthdir((float)((360.f / (float)sides) * (float)i) - (360.f / (float)sides), editor.GetScrollSpeed());
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