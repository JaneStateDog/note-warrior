#ifndef NOTE_WARRIOR_NOTE_H
#define NOTE_WARRIOR_NOTE_H

#include "raylib.h"


class Note {
protected:
    int side;
    int size;

    float distance; //Distance to center of polygon

    Color color = ORANGE;

    float hitTime;

public:
    Note(int inSide, int inSize, float inHitTime, float inDistance);


    void SetSide(int inSide);
    int GetSide() const;

    void SetSize(int inSize);
    int GetSize() const;

    void SetDistance(float inDistance);
    float GetDistance() const;

    float GetHitTime() const;


    virtual void Update();
    void Render() const;
};


#endif //NOTE_WARRIOR_NOTE_H