#ifndef NOTE_WARRIOR_MAINMENU_H
#define NOTE_WARRIOR_MAINMENU_H

#include <vector>


class MainMenu {
private:
    enum Options {
        Game = 0,
        Editor = 1,
        Quit = 2
    };

    int selected = 0;
    std::vector<Options> options = {Game, Editor, Quit};

public:
    void Update();
    void Render();
};


#endif //NOTE_WARRIOR_MAINMENU_H
