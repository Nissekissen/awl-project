#include "GameHandler.h"
#include "GameState.h"

GameHandler::GameHandler() {
    restartBtn.setBtnPin(6);
    pinMode(6, INPUT);
}

void GameHandler::restart() {
    gameState = GameState();
}

void GameHandler::loop() {
    restartBtn.loop();                                                                                                                                                          §
    if (restartBtn.isPressed()) {
        Serial.println("Pressed!");
        restart();
    }
    if (gameState.isRunning()) {
        gameState.loop();
    }
}