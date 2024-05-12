#include "mbed.h"
#include "cstdint"
#include "unordered_map"
#include "vector"

enum class tunes{
    C3,C3s,D3,D3s,E3,F3,F3s,G3,G3s,A3,A3s,B3,
    C4,C4s,D4,D4s,E4,F4,F4s,G4,G4s,A4,A4s,B4,
    C5,C5s,D5,D5s,E5,F5,F5s,G5,G5s,A5,A5s,B5,
    Pause,Sustain
};

void buzzer_soundset(PwmOut &IO,tunes input);
void buzzer_playmusic(PwmOut &IO,const vector<tunes>&Music, float tunesPerMin);
void play_CRY(PwmOut &IO);