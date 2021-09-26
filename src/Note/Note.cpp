#include "Note.h"


void Note::SetSide(int inSide) { side = inSide; }
void Note::SetSize(int inSize) { size = inSize; }

void Note::SetDistance(float inDistance) { distance = inDistance; }


void Note::Update() {
    //Make sure the note is not in the center
    if (distance > 0) {
        //If the note is unable to be blocked then continue moving
        if (!(distance <= (float)parentOctagon->GetSize() && distance >= (float)parentOctagon->GetSize() - 4.f
            && parentOctagon->GetSelectedSide() == side)) {
            distance -= 12;
        } else {
            //else loop through the notes and find self, then delete it
            for(auto iter = parentOctagon->notes.begin(); iter != parentOctagon->notes.end(); ++iter) {
                if (&(*iter) == this) {
                    parentOctagon->notes.erase(iter);
                    break;
                }
            }
        }
    }
}

void Note::Render() const {
    auto sides = (float)parentOctagon->GetSides();
    float angle = ((360.f / sides) * (float)side) + ((360.f / sides) / 2);

    Vector2 t1 = Lengthdir(angle, distance);
    Vector2 t2 = Lengthdir(angle,distance + (float)size);

    Vector2 spawnPoint = parentOctagon->GetPos();
    DrawLine((int)spawnPoint.x + (int)t1.x, (int)spawnPoint.y + (int)t1.y,
                (int)spawnPoint.x + (int)t2.x, (int)spawnPoint.y + (int)t2.y,
                    ORANGE);
}