#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "GameState.h"

class GameHandler {
    public:
        GameHandler();
        GameState gameState;
        void restart();
        void loop();
    private:
        Button restartBtn;
};

#endif