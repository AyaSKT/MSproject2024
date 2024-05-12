#include "buzzer_AyaSKT.h"

std::unordered_map<tunes,int>Tune2Freq={
    // 3rd
    {tunes::C3, 262},{tunes::C3s,277},
    {tunes::D3, 294},{tunes::D3s,311},
    {tunes::E3, 330},{tunes::F3, 349},
    {tunes::F3s,370},{tunes::G3, 392},
    {tunes::G3s,415},{tunes::A3, 440},
    {tunes::A3s,466},{tunes::B3, 494},
    // 4th
    {tunes::C4, 523},{tunes::C4s,554},
    {tunes::D4, 587},{tunes::D4s,622},
    {tunes::E4, 659},{tunes::F4, 698},
    {tunes::F4s,740},{tunes::G4, 784},
    {tunes::G4s,831},{tunes::A4, 880},
    {tunes::A4s,932},{tunes::B4, 988},
    // 5th
    {tunes::C5, 1047},{tunes::C5s,1109},
    {tunes::D5, 1175},{tunes::D5s,1245},
    {tunes::E5, 1319},{tunes::F5, 1397},
    {tunes::F5s,1480},{tunes::G5, 1568},
    {tunes::G5s,1661},{tunes::A5, 1760},
    {tunes::A5s,1865},{tunes::B5, 1976}

};

void buzzer_soundset(PwmOut &IO,tunes input){
    if(input==tunes::Pause) IO.period(1);
    else if(input!=tunes::Sustain){
        IO.period((float)1/(float)Tune2Freq[input]);
        IO.write(0.5);
    }
}

void buzzer_playmusic(PwmOut &IO,vector<pair<tunes,float>>Music, float tunesPerMin){
    auto delay_time=(60000/tunesPerMin);
    for(auto & [tune,beat]: Music){
        buzzer_soundset(IO,tune);
        ThisThread::sleep_for((uint32_t)(delay_time*beat));
    }
    buzzer_soundset(IO,tunes::Pause);
}

std::vector<pair<tunes,float>> music = {
        {tunes::E4,2},  {tunes::D4,1},  {tunes::C4,2},  {tunes::D4,1},//1
        {tunes::E4,1.5},{tunes::F4,0.5},{tunes::E4,1},  {tunes::D4,3},//2
        {tunes::E4,2},  {tunes::D4,1},  {tunes::C4,2},  {tunes::D4,1},//3
        {tunes::E4,1.5},{tunes::F4,0.5},{tunes::E4,1},  {tunes::D4,3},//4
        {tunes::E4,2},  {tunes::D4,1},  {tunes::C4,2},  {tunes::D4,1},//5
        {tunes::E4,1.5},{tunes::F4,0.5},{tunes::E4,1},  {tunes::D4,3},//6
        {tunes::E4,2},  {tunes::D4,1},  {tunes::C4,2},  {tunes::D4,1},//7
        {tunes::E4,1.5},{tunes::F4,0.5},{tunes::E4,1},  {tunes::D4,2},  {tunes::G3,0.5},{tunes::G3,0.5},//8
        {tunes::E4,1},  {tunes::E4,1},  {tunes::D4,1},  {tunes::F4,1},  {tunes::E4,1},  {tunes::D4,1},//9
        {tunes::D4,1},  {tunes::D4,1},  {tunes::C4,0.5},{tunes::C4,0.5},{tunes::F4,1},  {tunes::E4,1},  {tunes::D4,1},
        {tunes::D4,2},  {tunes::C4,0.5},{tunes::D4,0.5},{tunes::E4,3},
        {tunes::Pause,3}, {tunes::E3,1},{tunes::G3,1},  {tunes::C4,1},//12
        {tunes::B3,2},  {tunes::C4,1},  {tunes::B3,2},  {tunes::C4,1},//13
        {tunes::B3,0.5},{tunes::A3,0.5},{tunes::G3,2},  {tunes::G3,1},  {tunes::D3,1},  {tunes::F3,1},
        {tunes::F3,2},  {tunes::E3,1},  {tunes::E3,2},  {tunes::C3,1},//Uncertain
        {tunes::F3,1},  {tunes::E3,1},  {tunes::D3,1},  {tunes::E3,2},  {tunes::G3,1},//16
        
 };

 void play_CRY(PwmOut &IO){
    buzzer_playmusic(IO,music,200);
 }