#ifndef NOTE_WARRIOR_OCTAGON_H
#define NOTE_WARRIOR_OCTAGON_H

#include "raylib.h"
#include <vector>

#include "../Functions/Functions.h"
#include "../ControlsController/ControlsController.h"
#include "Note/Note.h"


class Note;

class Octagon {
private:
    Vector2 pos;
    int size;

    int sides;
    int selSide = 0;

    bool moveFlipper = false;

public:
    std::vector<Note> notes;


    Octagon() = default;
    Octagon(Vector2 inPos, int inSize, int inSides)
        : pos(inPos), size(inSize), sides(inSides)
    {}


    void SetPos(Vector2 inPos);
    Vector2 GetPos();

    void SetSize(int inSize);
    int GetSize() const;

    int GetSelectedSide() const;

    int GetSides() const;


    void Update();
    void Render() const;
};


#endif //NOTE_WARRIOR_OCTAGON_H
