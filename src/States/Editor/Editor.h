#ifndef NOTE_WARRIOR_EDITOR_H
#define NOTE_WARRIOR_EDITOR_H

#include <vector>

#include "../../Octagon/Octagon.h"
#include "../../Octagon/Note/Note.h"
#include "../../Octagon/Note/MappingNote/MappingNote.h"


class MappingNote;

class Editor {
private:
    Octagon octagon;

    std::vector<Note> notes;
    std::vector<MappingNote> mappingNotes;

    bool playing = false;
    float playedAt = 0;

    float songTime = 0;
    float songLength = 120; //Assume song is two minutes long for debugging purposes

    float scrollSpeed = 3;

public:
    Editor();


    std::vector<Note>* GetNotes();
    std::vector<MappingNote>* GetMappingNotes();

    Octagon* GetOctagon();

    float GetSongLength() const;
    float GetSongTime() const;

    float GetScrollSpeed() const;


    void Update();
    void Render();
};


#endif //NOTE_WARRIOR_EDITOR_H
