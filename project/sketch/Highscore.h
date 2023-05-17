#ifndef HIGHSCORE_H
#define HIGHSCORE_H

class Highscore {
    public:
        Highscore();
        void addScore(int score);
        void getScores(int* scores);
        void save();
    private:
        int highscores[4] = {0};
        int readScores();
        void writeScores(); 
};

#endif