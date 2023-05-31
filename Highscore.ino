#include "Highscore.h"
#include <EEPROM.h>


int sort_desc(const void *cmp1, const void *cmp2)
{
  // Need to cast the void * to int *
  int a = *((int *)cmp1);
  int b = *((int *)cmp2);
  // The comparison
  return a > b ? -1 : (a < b ? 1 : 0);
  // A simpler, probably faster way:
  //return b - a;
}

Highscore::Highscore() {
    readScores();
}

void Highscore::addScore(int score) {

    // The array has 4 spots, so when a score is added, it's placed at the fourth spot, the array is sorted and the fourth spot is cleared.

    highscores[3] = score;
    qsort(highscores, 4, sizeof(highscores[0]), sort_desc);
    highscores[3] = 0;
}

void Highscore::getScores(int* scores) {
    readScores();
    for (int i = 0; i < 3; i++) {
      scores[i] = highscores[i];
    }
}

int Highscore::readScores() {
    for (int i = 0; i < 3; i++) {
        long val = EEPROMReadlong(i * 4);
        int valInt = val;
        if (valInt == -1) { valInt = 0; } // If there is no previous score, EEPROMReadlong returns -1
        highscores[i] = valInt;
    }
}

void Highscore::writeScores() {
    for (int i = 0; i < 3; i++) {
        long val = highscores[i];
        EEPROMWritelong(i * 4, val);
    }
}

void Highscore::resetScores() {
  for (int i = 0; i < 3; i++) {
      long val = 0;
      EEPROMWritelong(i * 4, 0);
  }
}

void Highscore::save() {
    writeScores();
}

long EEPROMReadlong(long address) {
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(int address, long value) {
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}