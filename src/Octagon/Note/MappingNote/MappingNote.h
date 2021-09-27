#ifndef NOTE_WARRIOR_MAPPINGNOTE_H
#define NOTE_WARRIOR_MAPPINGNOTE_H

#include "../Note.h"


class MappingNote : public Note {
public:
    MappingNote(int inSide, int inSize, float inHitTime, float inDistance);


    void Update() override;
};


#endif //NOTE_WARRIOR_MAPPINGNOTE_H
