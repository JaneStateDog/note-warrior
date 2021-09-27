#include "Note.h"

#include "../../Functions/Functions.h"
#include "../../main.h"


Note::Note(int inSide, int inSize, float inHitTime, float inDistance)
        : side(inSide), size(inSize), distance(inDistance), hitTime(inHitTime)
{}

void Note::SetSide(int inSide) { side = inSide; }
int Note::GetSide() const { return side; }

void Note::SetSize(int inSize) { size = inSize; }
int Note::GetSize() const { return size; }

void Note::SetDistance(float inDistance) { distance = inDistance; }
float Note::GetDistance() const { return distance; }

float Note::GetHitTime() const { return hitTime; }


void Note::Update() {
    distance -= editor.GetScrollSpeed();

    if (distance <= 0) {
        if (editor.GetOctagon()->GetSelectedSide() != side) { editor.GetOctagon()->SetFlashing(true); }

        if (distance < editor.GetScrollSpeed() - (float)size) {
            int p = 0;
            for (auto & note : *editor.GetNotes()) {
                if (&note == this) {
                    editor.GetNotes()->erase(editor.GetNotes()->begin() + p);
                    break;
                }

                p++;
            }
        }
    }
}

void Note::Render() const {
    int sides = editor.GetOctagon()->GetSides();
    auto octSize = (float)editor.GetOctagon()->GetSize();

    for (int i = 1; i <= size * 2; i++) {
        float initAngle = (360.f / (float)sides);

        float angle1 = initAngle * (float)side;
        float angle2 = angle1 + initAngle;

        float dis = distance + ((float)i / 2);
        if (dis < 0) { continue; }

        Vector2 t1 = Lengthdir(angle1, dis);
        Vector2 t2 = Lengthdir(angle2, dis);

        Vector2 offset1 = Lengthdir(angle1, octSize);
        Vector2 offset2 = Lengthdir(angle2, octSize);


        Vector2 spawnPoint = editor.GetOctagon()->GetPos();
        DrawLine((int)spawnPoint.x + (int)t1.x + (int)offset1.x, (int)spawnPoint.y + (int)t1.y + (int)offset1.y,
                 (int)spawnPoint.x + (int)t2.x + (int)offset2.x, (int)spawnPoint.y + (int)t2.y + (int)offset2.y,
                 color);
    }
}