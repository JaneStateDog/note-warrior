#include "main.h"


int main() {
    winSize = {800, 450};
    octagon = Octagon({winSize.x / 2.f, winSize.y / 2.f}, 128, 8);

    InitWindow((int)winSize.x, (int)winSize.y, "note-warrior");
    SetTargetFPS(30);
    Loop();
    CloseWindow();


    return 0;
}


void Loop() {
    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}


void Update() {
    octagon.Update();
}

void Render() {
    BeginDrawing();
    ClearBackground(BLACK);

    octagon.Render();

    EndDrawing();
}