#include "mbed.h"
#include "i2c_oled\i2c_oled.h"
#include "cstdint"
#include "buzzer_AyaSKT\buzzer_AyaSKT.h"

BusIn keys(A1,A2,A3,A0,A5,A6,A7);
void OLED_Show_Condition(void){
    auto num=keys.read();
    long long res=0;
    for(auto i=1,j=1;i<=0x10000000;i<<=1,j*=10){
        if((i&num)==i) res+=j;
    }
    OLED_ShowNumBuffered(0,0,res,8,8,1);
    OLED_SendBuffer();
}

InterruptIn Modes_button(D12);
PwmOut buzzer(D10);
DigitalOut VCC(D11);

int mode=1;

void Mode_Switch(void){
    mode++;
    if(mode==4) mode=1;
    OLED_ShowNumBuffered(97,97,mode,1,8,1);
    ThisThread::sleep_for(200ms);
}

extern std::unordered_map<tunes,int>Tune2Freq;
extern std::vector<pair<tunes,float>>music;

int main(){
    //buzzer.period(0.0f);
    //ThisThread::sleep_for(20s);
    //buzzer_soundset(buzzer,tunes::C3s);
    

    OLED_Init();
    OLED_ClearBuffer();

    Modes_button.mode(PullDown);
    Modes_button.rise(&Mode_Switch);
    keys.mode(PullDown);
    //OLED_Genshin();

    
    
    while(1){ 
        OLED_ShowStringBuffered(88,75,"Mode",8,1);
        
        OLED_DrawCircleBuffered(100,100,12);
        OLED_DrawLineBuffered(75,0,75,64,1);

        OLED_Show_Condition();
       
        OLED_SendBuffer();
        if(mode==1){
            
        }
        else if(mode==2){
            
            VCC=0;
            ThisThread::sleep_for(3s);
            VCC=1;
            play_CRY(buzzer);
            VCC=0;
        }
        else if(mode==3){
            
        }


        ThisThread::sleep_for(20ms);
        //OLED_ClearBuffer();
    }
}