#include "MainMenu.h"

#include "raylib.h"
#include <string>

#include "../../ControlsController/ControlsController.h"
#include "../../main.h"


void MainMenu::Update() {
    if (Controls::KeyUpPressed) { selected--; }
    else if (Controls::KeyDownPressed) { selected++; }

    if (selected == options.size()) { selected = 0; }
    else if (selected == -1) { selected = (int)(options.size() - 1); }


    if (Controls::KeyEnterPressed) {
        switch (selected) {
            case Game:
                //state = States::Game;
                break;

            case Editor:
                state = States::Editor;
                break;

            case Quit:
                CloseWindow();
                break;
        }
    }
}

void MainMenu::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);


    int i = 0;
    for (auto & option : options) {
        int x = 14;
        int y = 14 + (52 * i);

        std::string displayString = "Hello";

        switch (option) {
            case Game:
                displayString = "Game";
                break;

            case Editor:
                displayString = "Editor";
                break;

            case Quit:
                displayString = "Quit";
                break;
        }


        DrawText(displayString.c_str(), x, y, 48, WHITE);
        if (i == selected) { DrawRectangleLines(x - 6, y, 156, 48, WHITE); }

        i++;
    }


    EndMode2D();
    EndDrawing();
}