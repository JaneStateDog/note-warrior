#ifndef NOTE_WARRIOR_EDITOR_H
#define NOTE_WARRIOR_EDITOR_H

#include <vector>

#include "../../Polygon/Polygon.h"
#include "../../Polygon/Note/Note.h"
#include "../../Polygon/Note/MappingNote/MappingNote.h"


class MappingNote;

class Editor {
private:
    Polygon polygon;

    std::vector<Note> notes;
    std::vector<MappingNote> mappingNotes;

    bool playing = false;
    float playedAt = 0;

    float songTime = 0;
    float songLength = 120; //Assume song is two minutes long for debugging purposes

    float scrollSpeed = 3;

    float mouseSongTime = 0;

public:
    Editor();


    std::vector<Note>* GetNotes();
    std::vector<MappingNote>* GetMappingNotes();

    Polygon* GetPolygon();

    float GetSongLength() const;
    float GetSongTime() const;

    float GetScrollSpeed() const;


    void Update();
    void Render();
};


#endif //NOTE_WARRIOR_EDITOR_H
