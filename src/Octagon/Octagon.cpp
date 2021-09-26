#include "Octagon.h"


void Octagon::SetPos(Vector2 inPos) { pos = inPos; }
Vector2 Octagon::GetPos() { return pos; }

void Octagon::SetSize(int inSize) { size = inSize; }
int Octagon::GetSize() const { return size; }

int Octagon::GetSelectedSide() const { return selSide; }

int Octagon::GetSides() const { return sides; }


void Octagon::Update() {
    if (moveFlipper) {
        if (Controls::KeyLeft) { selSide--; }
        else if (Controls::KeyRight) { selSide++; }

        moveFlipper = false;
    } else { moveFlipper = true; }

    if (selSide < 0) { selSide = sides - 1; }
    else if (selSide > sides - 1) { selSide = 0; }



    //This creates a note
    //notes.emplace_back(0, 10, this);

    //Update notes
    for (auto & note : notes) {
        note.Update();
    }
}

void Octagon::Render() const {
    int lastX;
    int lastY;

    Vector2 t1 = Lengthdir(0, (float) size);
    int newX = (int)t1.x;
    int newY = (int)t1.y;

    for (int i = 1; i <= sides; i++) {
        lastX = newX;
        lastY = newY;

        Vector2 t2 = Lengthdir((float) ((360.f / (float)sides) * (float)i), (float) size);
        newX = (int)t2.x;
        newY = (int)t2.y;

        Color color = WHITE;

        if (selSide + 1 == i) { color = RED; }

        DrawLine((int)pos.x + lastX, (int)pos.y + lastY,
                    (int)pos.x + newX, (int)pos.y + newY,
                        color);
    }

    //Render notes
    for (auto & note : notes) {
        note.Render();
    }
}