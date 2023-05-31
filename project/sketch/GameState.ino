#include "GameState.h"


GameState::GameState() {
    for (int i = 0; i < getBtnsLength(); i++) {
        btns[i].setLampPin(i + 32);
        btns[i].setBtnPin(i + 22);
        pinMode(btns[i].getBtnPin(), INPUT_PULLUP);
        pinMode(btns[i].getLampPin(), OUTPUT);

        btns[i].setLamp(LOW);
    }

    // highscore.resetScores();

    running = true;

    nextBtn = getNextRandomBtn();
    btns[nextBtn].setLamp(HIGH);

    score = 0;
    scoreTimer = 100;

    lcd.begin(16, 2);

    lcd.print("Score: ");
    lcd.print(score);

}

int GameState::getNextBtn() {
    return nextBtn;
}

bool GameState::isRunning() {
    return running;
}

void GameState::loop() {
    for (auto btn: btns) {
        btn.loop();
        if (btn.isPressed() == HIGH) {
            if (getBtnIndex(btn) == nextBtn) { // If the correct button is pressed
                btn.setLamp(LOW);
                score += static_cast<int>(scoreTimer);
                lcd.clear(); 
                lcd.print("Score: ");
                lcd.print(score);

                lcd.setCursor(0, 1);
                lcd.print("+");
                lcd.print(scoreTimer);

                delay(500);

                lastBtn = nextBtn;
                nextBtn = getNextRandomBtn();
                btns[nextBtn].setLamp(HIGH);

                scoreTimer = 100;
                

            } else { // If the wrong button is pressed
                btns[nextBtn].setLamp(LOW);

                lcd.clear();
                lcd.print("Wrong Button!");

                delay(300);

                for (int x = 0; x < 2; x++) {
                    for (int i = 0; i < getBtnsLength(); i++) {
                        btns[i].setLamp(HIGH);
                    }
                    delay(200);
                    for (int i = 0; i < getBtnsLength(); i++) {
                        btns[i].setLamp(LOW);
                    }
                    delay(200);
                }
                lastBtn = nextBtn;
                nextBtn = getNextRandomBtn();
                btns[nextBtn].setLamp(HIGH);

                scoreTimer = 100;

                lcd.clear();
                lcd.print("Score: ");
                lcd.print(score);

            }
        }
    }
    if (scoreTimer > 10) {
        scoreTimer -= 0.5;
    }

    if (timer <= 0) {

        running = false;
        gameOver();

    }
    
    timer--;
    delay(25);
}

int GameState::getBtnIndex(Button btn) {
  for (int i = 0; i < getBtnsLength(); i++) {
    if (btn.getBtnPin() == btns[i].getBtnPin()) {
      return i;
    }    
  }

  /* if no match found */
    return -1;
}

int GameState::getBtnsLength() {
    int c = 0;
    for (auto i : btns) {
        c++;
    }
    return c;
}

int GameState::getNextRandomBtn() {
    int btn;
    do {
        randomSeed(analogRead(0));
        btn = random(0, getBtnsLength());
    } while (btn == lastBtn);
    return btn;
}

void GameState::gameOver() {

    for (auto btn : btns) {
        btn.setLamp(LOW);
    }


    highscore.getScores(highscores);

    // Serial.println(highscores[0]);

    highscore.addScore(score);
    highscore.save();
    highscore.getScores(highscores);

    // highscore.resetScores();


    lcd.clear();
    lcd.print("Game Over!");

    delay(1000);

    lcd.clear();
    lcd.print("Highscores:");

    delay(1000);

    for (int i = 0; i < 3; i++) {
        lcd.clear();
        lcd.print(i+1);
        lcd.print(". ");
        lcd.print(highscores[i]);

        delay(3000);
    }

    lcd.clear();
    lcd.print("Press start to");
    lcd.setCursor(0, 1);
    lcd.print("play again!");

}