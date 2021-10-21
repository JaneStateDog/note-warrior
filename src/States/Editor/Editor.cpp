#include "Editor.h"

#include "raylib.h"
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

#include "../../Functions/Functions.h"
#include "../../ControlsController/ControlsController.h"
#include "../../main.h"


Editor::Editor()
    : polygon(Polygon({screenSize.x / 2.f, screenSize.y / 2.f}, standardPolygonSize, 8))
{}


std::vector<Note>* Editor::GetNotes() { return &notes; }
std::vector<MappingNote>* Editor::GetMappingNotes() { return &mappingNotes; }

Polygon* Editor::GetPolygon() { return &polygon; }

float Editor::GetSongLength() const { return songLength; }
float Editor::GetSongTime() const { return songTime; }

float Editor::GetScrollSpeed() const { return scrollSpeed; }


void Editor::Update() {
    mouseSongTime = songTime + (std::round(polygon.GetDistanceOfMouse() / scrollSpeed) / (float)GetFPS());

    if (!playing) {
        if (Controls::MouseLeftPressed) {
            mappingNotes.emplace_back(polygon.GetSideOfMouse(), 8, mouseSongTime,0);
        } else if (Controls::MouseRightPressed) {
            int p = 0;
            for (auto & note : mappingNotes) {
                if ((mouseSongTime < note.GetHitTime() + (scrollSpeed / (float)GetFPS()) &&
                        mouseSongTime > note.GetHitTime() - (scrollSpeed / (float)GetFPS())) &&
                        note.GetSide() == polygon.GetSideOfMouse()) {
                    mappingNotes.erase(mappingNotes.begin() + p);
                    break;
                }

                p++;
            }
        }

        songTime -= Controls::MouseWheelMovement / 8;
    } else { songTime += GetFrameTime(); }

    //Clamp song time
    if (songTime > songLength) { songTime = songLength; }
    else if (songTime < 0) { songTime = 0; }


    if (!playing) {
        for (auto & note : mappingNotes) { note.Update(); }
    } else {
        for (auto & note : notes) { note.Update(); }
    }

    polygon.Update();


    if (Controls::KeyEnterPressed) {
        if (!playing) {
            for (auto & note : mappingNotes) {
                notes.emplace_back(note.GetSide(), note.GetSize(), note.GetHitTime(), note.GetDistance());
            }

            playing = true;
            playedAt = songTime;
        } else {
            notes.clear();

            playing = false;
            songTime = playedAt;
        }
    }


    if (Controls::KeyUp) { camera.zoom += 0.03; }
    else if (Controls::KeyDown) { camera.zoom -= 0.03; }

    if (camera.zoom <= 0.5) { camera.zoom = 0.5; }
    else if (camera.zoom > 6) { camera.zoom = 6; }


    if (Controls::F11Pressed) {
        std::string path = "C:/Projects/note-warrior/test.json";
        std::ofstream stream(path.c_str());

        std::string data;
        data = "{\n";

        bool first = true;
        for (auto & note : mappingNotes) {
            if (!first) { data += ",\n"; }
            if (first) { first = false; }

            data += "   ";
            data += '"';
            data += std::to_string(note.GetHitTime());
            data += '"';
            data += ": ";

            data += "[";
            data += std::to_string(note.GetSide());
            data += ",";
            data += std::to_string(note.GetSize());
            data += "]";
        }

        stream << data << "\n}";

        std::cout << "Sending" << std::endl;
    }
}

void Editor::Render() {
    BeginDrawing();
    ClearBackground(BLACK);


    //World space
    BeginMode2D(camera);

    if (!playing) {
        for (auto & note : mappingNotes) {
            note.Render();
        }
    } else {
        for (auto & note : notes) {
            note.Render();
        }
    }

    polygon.Render(!playing);

    EndMode2D();


    //UI
    BeginMode2D(UICamera);

    Color timeBarColor = BLUE;
    if (playing) { timeBarColor = ORANGE; }
    DrawLine(12, 12,
             (int)(screenSize.x - ValueFromTwoRanges(0, songLength, songTime, 12, screenSize.x - 12)),
             12, timeBarColor);

    DrawText((std::to_string(songTime) + "/" + std::to_string(songLength)).c_str(), 12, 18, 20, WHITE);
    DrawText(("Mouse song time:" + std::to_string(mouseSongTime)).c_str(), 12, 36, 20, WHITE);

    EndMode2D();


    EndDrawing();
}