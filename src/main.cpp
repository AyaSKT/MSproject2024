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
    OLED_SendBuffer();

    //goto label;
    //OLED_ClearBuffer();
    wait_us(30000);
}

extern std::unordered_map<tunes,int>Tune2Freq;
extern std::vector<pair<tunes,float>>music;

void OLED_Clear_Left(void){
    for(int i=0;i<=63;i++){
        OLED_DrawLineBuffered(8,i,75,8,0);
    }
    OLED_SendBuffer();
}

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
    VCC=0;
    
    OLED_ShowNumBuffered(97,97,mode,1,8,1);



    wait_us(1000000);
    OLED_ShowStringBuffered(89,75,"Mode",8,1);
        
    OLED_DrawCircleBuffered(100,100,12);
    OLED_DrawCircleBuffered(100,100,10);
    OLED_DrawLineBuffered(75,0,75,64,1);
    OLED_SendBuffer();
    for(int i=7;i>=1;i--){
                OLED_ShowNumBuffered(0,(i-1)*8+i,8-i,1,8,1);
            }
    while(1){ 
        

        //OLED_Show_Condition();
       
        OLED_SendBuffer();
            
            
        //buzzer_soundset(buzzer,tunes::C3,VCC);    
        
        if(mode==1){
            
            if(keys.read()!=0){
                if(keys.read()==0b1)
                    {buzzer_soundset(buzzer,tunes::C4,VCC,1); OLED_DrawLineBuffered(8,56,75,8,1);}
                else if(keys.read()==0b10)
                    {buzzer_soundset(buzzer,tunes::D4,VCC,1); OLED_DrawLineBuffered(8,48,75,8,1);}
                else if(keys.read()==0b100)
                    {buzzer_soundset(buzzer,tunes::E4,VCC,1); OLED_DrawLineBuffered(8,40,75,8,1);}
                else if(keys.read()==0b1000)
                    {buzzer_soundset(buzzer,tunes::F4,VCC,1); OLED_DrawLineBuffered(8,32,75,8,1);}
                else if(keys.read()==0b10000)
                    {buzzer_soundset(buzzer,tunes::G4,VCC,1); OLED_DrawLineBuffered(8,24,75,8,1);}
                else if(keys.read()==0b100000)
                    {buzzer_soundset(buzzer,tunes::A4,VCC,1); OLED_DrawLineBuffered(8,16,75,8,1);}
                else if(keys.read()==0b1000000)
                    {buzzer_soundset(buzzer,tunes::B4,VCC,1); OLED_DrawLineBuffered(8, 8,75,8,1);}
                OLED_SendBuffer();
            }
            else {buzzer_soundset(buzzer,tunes::Pause,VCC,1); OLED_Clear_Left();}
            ThisThread::sleep_for(50ms);
        }
        else if(mode==2){
            
            //VCC=0;
            OLED_Clear_Left();
            wait_us(1000000);
            if(mode!=2) continue;
            
            OLED_ShowStringBuffered(10,20,"Playing",8,1);
            OLED_ShowStringBuffered(10,38,"Haruhikage",8,1);

            OLED_ShowNumBuffered(97,97,mode,1,8,1);
            OLED_SendBuffer();

            play_CRY(buzzer,VCC,mode==2);

            OLED_ShowNumBuffered(97,97,mode,1,8,1);
            OLED_SendBuffer();
            ThisThread::sleep_for(500ms);
            mode=1;
            
            
        }
        else if(mode==3){
            OLED_Clear_Left();
            wait_us(1000000);

            if(mode!=3) continue;
            
            OLED_ShowStringBuffered(10,20,"Playing",8,1);
            OLED_ShowStringBuffered(10,38,"SecretBase",8,1);

            OLED_ShowNumBuffered(97,97,mode,1,8,1);
            OLED_SendBuffer();

            play_SCB(buzzer,VCC,mode==3);

            OLED_ShowNumBuffered(97,97,mode,1,8,1);
            OLED_SendBuffer();
            ThisThread::sleep_for(500ms);
            mode=1;
        }

        OLED_ShowNumBuffered(97,97,mode,1,8,1);
        OLED_SendBuffer();
        //ThisThread::sleep_for(20ms);
       // OLED_ClearBuffer();
       
    }
}// todo : add a mode switch button