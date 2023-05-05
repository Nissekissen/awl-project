

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Button.h"
#include "Highscore.h"
#include "LCDHandler.h"

class GameState {
    public:
        GameState();
        int getNextBtn();
        void loop();
        bool isRunning();
    private:
        Button btns[2];
        int nextBtn; // Button index for the next button
        int lastBtn; // Button index for the last button, so that the same lamp can't light up twice in a row
        int getBtnIndex(Button btn);
        int getBtnsLength();
        int getNextRandomBtn();
        LCDHandler lcd;
        int score;
        int scoreTimer; // Counts down from 100 when a lamp is lit up.
        int timer = 40 * 15;
        Highscore highscore;
        int highscores[3];
        bool running;
        void gameOver();
};

#endif