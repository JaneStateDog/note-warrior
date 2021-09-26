#include "Octagon.h"


void Octagon::SetPos(Vector2 inPos) { pos = inPos; }
Vector2 Octagon::GetPos() { return pos; }

void Octagon::SetSize(int inSize) { size = inSize; }
int Octagon::GetSize() const { return size; }

int Octagon::GetSelectedSide() const { return selSide; }

int Octagon::GetSides() const { return sides; }


void Octagon::Update() {
    if (move == 1) {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D)) { move++; }
    } else if (move >= 2) {
        if (IsKeyDown(KEY_A)) { selSide--; }
        else if (IsKeyDown(KEY_D)) { selSide++; }

        move = 0;
    } else {
        if (IsKeyPressed(KEY_A)) { selSide--; }
        else if (IsKeyPressed(KEY_D)) { selSide++; }

        move = 1;
    }

    if (selSide < 0) { selSide = sides - 1; }
    else if (selSide > sides - 1) { selSide = 0; }



    //Create notes poorly
    if (make >= 8) {
        notes.emplace_back(choosenSide, size, this);

        make = 0;
        choosenSide++;

        if (choosenSide >= sides) { choosenSide = 0; }
    } else { make++; }

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