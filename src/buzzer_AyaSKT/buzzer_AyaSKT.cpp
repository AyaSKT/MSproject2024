#include "buzzer_AyaSKT.h"



std::unordered_map<tunes,int>Tune2Freq={
    // 2nd
    {tunes::G2,196},{tunes::A2,220},{tunes::B2,247},
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

void buzzer_soundset(PwmOut &IO,tunes input,DigitalOut &VCC,bool condi){
    if(condi==false) return;
    if(input==tunes::Pause) VCC=0;
    else if(input!=tunes::Sustain){
        VCC=1;
        IO.period((float)1/(float)Tune2Freq[input]);
        IO.write(0.2f);
    }
}



void buzzer_playmusic(PwmOut &IO,vector<pair<tunes,float>>Music, float tunesPerMin,DigitalOut &VCC,bool condi){
    auto delay_time=(60000/tunesPerMin);
    for(auto & [tune,beat]: Music){
        buzzer_soundset(IO,tune,VCC,condi);
        ThisThread::sleep_for((uint32_t)(delay_time*beat));
    }
    buzzer_soundset(IO,tunes::Pause,VCC,condi);
}

std::vector<pair<tunes,float>> music1 = {
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
        {tunes::Pause,3},{tunes::E3,1},{tunes::G3,1},  {tunes::C4,1},//12
        {tunes::B3,2},  {tunes::C4,1},  {tunes::B3,2},  {tunes::C4,1},//13
        {tunes::B3,0.5},{tunes::A3,0.5},{tunes::G3,2},  {tunes::G3,1},  {tunes::D3,1},  {tunes::F3,1},
        {tunes::F3,2},  {tunes::E3,1},  {tunes::E3,2},  {tunes::G2,1},//Uncertain
        {tunes::F3,1},  {tunes::E3,1},  {tunes::D3,1},  {tunes::E3,2},  {tunes::G3,1},//16
        {tunes::C3,3},  {tunes::Pause,2},{tunes::C3,1},//17
        {tunes::D3,1},  {tunes::C3,1.5},{tunes::B2,0.5},{tunes::C3,1},{tunes::G3,1},{tunes::C3,1},
        {tunes::F3,2},  {tunes::E3,1},  {tunes::D3,1},  {tunes::C3,1},{tunes::C3,1},
        {tunes::C3,3},  {tunes::Pause,2},{tunes::C3,0.5},{tunes::D3,0.5},//20
        {tunes::E3,1},  {tunes::E3,1},  {tunes::D3,1},  {tunes::F3,1},  {tunes::E3,1},  {tunes::D3,1},//21
        {tunes::D3,1},  {tunes::D3,1},  {tunes::C3,1},  {tunes::F3,1},  {tunes::E3,1},  {tunes::D3,1},//22
        {tunes::D3,2},  {tunes::C3,0.5},{tunes::D3,0.5},{tunes::E3,3},
        {tunes::Pause,3},{tunes::E3,1},{tunes::G3,1},  {tunes::C4,1},//24
        {tunes::B3,2},  {tunes::C4,1},  {tunes::B3,2},  {tunes::C4,1},//25
        {tunes::B3,0.5},{tunes::A3,0.5},{tunes::G3,2},  {tunes::G3,1},  {tunes::D3,1},  {tunes::F3,1},
        {tunes::F3,1},  {tunes::E3,1},  {tunes::E3,1},  {tunes::C3,2},  {tunes::G2,1},//Uncertain
        {tunes::F3,1},  {tunes::E3,1},  {tunes::D3,1},  {tunes::E3,2},  {tunes::G3,1},//28
        {tunes::C3,3},  {tunes::Pause,2},{tunes::C3,1},//29
        {tunes::D3,1},  {tunes::C3,2},  {tunes::C3,1},  {tunes::G3,1},  {tunes::C3,1},
        {tunes::F3,1},  {tunes::F3,1},  {tunes::E3,0.5},{tunes::D3,0.5},{tunes::D3,1},{tunes::C3,1},{tunes::C3,1},
        {tunes::C3,6}//32
        
 };

std::vector<pair<tunes,float>> music2 = {
        {tunes::E4,2},  {tunes::D4,1},  {tunes::C4,2},  {tunes::D4,1}//1

};

 void play_CRY(PwmOut &IO,DigitalOut &VCC,bool condi){
    buzzer_playmusic(IO,music1,200,VCC,condi);
 }
 void play_SCB(PwmOut &IO,DigitalOut &VCC,bool condi){
    buzzer_playmusic(IO,music2,200,VCC,condi);
 }