#ifndef NOTE_WARRIOR_NOTE_H
#define NOTE_WARRIOR_NOTE_H

#include "raylib.h"

#include "../Functions.h"
#include "../Octagon/Octagon.h"


class Octagon;

class Note {
private:
    int side;
    int size;

    float distance = 400; //Distance to center of octagon

    Octagon* parentOctagon;

public:
    Note(int inSide, int inSize, Octagon* inParentOctagon)
        : side(inSide), size(inSize), parentOctagon(inParentOctagon)
    {}


    void SetSide(int inSide);
    void SetSize(int inSize);

    void SetDistance(float inDistance);


    void Update();
    void Render() const;
};


#endif //NOTE_WARRIOR_NOTE_H