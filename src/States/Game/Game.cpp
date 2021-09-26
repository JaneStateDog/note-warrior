#include "Game.h"


Game::Game(Vector2 winSize) {
    octagon = Octagon({winSize.x / 2.f, winSize.y / 2.f}, 128, 8);
}


void Game::Update() {
    octagon.Update();
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(BLACK);


    octagon.Render();


    EndDrawing();
}