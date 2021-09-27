#include "MappingNote.h"


#include "../../../main.h"


MappingNote::MappingNote(int inSide, int inSize, float inHitTime, float inDistance)
    : Note(inSide, inSize, inHitTime, inDistance)
{ color = BLUE; }


void MappingNote::Update() {
    distance = ((hitTime * (float)GetFPS() * editor.GetScrollSpeed()) - ((editor.GetSongTime() *
                (float)GetFPS()) * editor.GetScrollSpeed()));
}