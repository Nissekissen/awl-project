#include "GameHandler.h"
#include "GameState.h"

GameHandler::GameHandler() {
    restartBtn.setBtnPin(48);
    pinMode(48, INPUT);
}

void GameHandler::restart() {
    gameState = GameState();
}

void GameHandler::loop() {
    // restartBtn.loop();
    if (restartBtn.isPressed()) {
        // restart();
    }
    if (gameState.isRunning()) {
        gameState.loop();
    }
}