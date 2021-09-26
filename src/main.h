#ifndef NOTE_WARRIOR_MAIN_H
#define NOTE_WARRIOR_MAIN_H

#include "raylib.h"
#include <vector>

#include "Functions.h"
#include "Octagon/Octagon.h"


Vector2 winSize;

Octagon octagon;


void Loop();

void Update();
void Render();


#endif //NOTE_WARRIOR_MAIN_H