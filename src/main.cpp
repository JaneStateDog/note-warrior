#include "main.h"


//Global variables
Vector2 winSize = {800, 450};


States::states state = States::MainMenu;

MainMenu mainMenu;
Game game(winSize);


int main() {
    InitWindow((int)winSize.x, (int)winSize.y, "note-warrior");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        Controls::Update();

        switch (state) {
            case States::MainMenu:
                mainMenu.Update();
                mainMenu.Render();

                break;

            case States::Game:
                game.Update();
                game.Render();

                break;

            case States::Editor:

                break;
        }
    }

    CloseWindow();
    return 0;
}