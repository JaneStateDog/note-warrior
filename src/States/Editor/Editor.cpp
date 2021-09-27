#include "Editor.h"

#include "raylib.h"
#include <string>

#include "../../Functions/Functions.h"
#include "../../ControlsController/ControlsController.h"
#include "../../main.h"


Editor::Editor()
    : octagon(Octagon({screenSize.x / 2.f, screenSize.y / 2.f}, standardOctagonSize, 8))
{}


std::vector<Note>* Editor::GetNotes() { return &notes; }
std::vector<MappingNote>* Editor::GetMappingNotes() { return &mappingNotes; }

Octagon* Editor::GetOctagon() { return &octagon; }

float Editor::GetSongLength() const { return songLength; }
float Editor::GetSongTime() const { return songTime; }

float Editor::GetScrollSpeed() const { return scrollSpeed; }


void Editor::Update() {
    if (!playing) {
        if (Controls::MouseLeftPressed) {
            mappingNotes.emplace_back(octagon.GetSelectedSide(), 8, songTime,0);
        } else if (Controls::MouseRightPressed) {
            int p = 0;
            for (auto & note : mappingNotes) {
                if (note.GetHitTime() == songTime && note.GetSide() == octagon.GetSelectedSide()) {
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

    octagon.Update();


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
}

void Editor::Render() {
    BeginDrawing();
    ClearBackground(BLACK);


    //UI
    BeginMode2D(UICamera);

    Color timeBarColor = BLUE;
    if (playing) { timeBarColor = ORANGE; }
    DrawLine(12, 12,
             (int)(screenSize.x - ValueFromTwoRanges(0, songLength, songTime, 12, screenSize.x - 12)),
             12, timeBarColor);

    DrawText((std::to_string(songTime) + "/" + std::to_string(songLength)).c_str(), 12, 18, 20, WHITE);

    EndMode2D();


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

    octagon.Render(!playing);

    EndMode2D();


    EndDrawing();
}