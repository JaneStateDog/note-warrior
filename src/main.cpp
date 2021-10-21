#include "main.h"

#include "ControlsController/ControlsController.h"


Vector2 screenSize = {640, 360};
Camera2D camera;
Camera2D UICamera;


States::states state = States::MainMenu;

MainMenu mainMenu;
//Game game;
Editor editor;


int standardPolygonSize = 36;


int main() {
    float winResizeMultiplier = 2.5f;

    InitWindow((int)(screenSize.x * winResizeMultiplier), (int)(screenSize.y * winResizeMultiplier),
                "note-warrior");

    camera.offset = {(screenSize.x * winResizeMultiplier) / 2, (screenSize.y * winResizeMultiplier) / 2};
    camera.target = {screenSize.x / 2, screenSize.y / 2};
    camera.zoom = winResizeMultiplier;

    UICamera.zoom = winResizeMultiplier;

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        Controls::Update();


        //Updates
        switch (state) {
            case States::MainMenu: mainMenu.Update(); break;
            case States::Game: /*game.Update();*/ break;
            case States::Editor: editor.Update(); break;
        }

        //Renders
        switch (state) {
            case States::MainMenu: mainMenu.Render(); break;
            case States::Game: /*game.Render();*/ break;
            case States::Editor: editor.Render(); break;
        }
    }

    CloseWindow();
    return 0;
}