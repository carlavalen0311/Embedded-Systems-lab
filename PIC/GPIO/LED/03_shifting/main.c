#include <pic.h>

#define led PORTB

void delay(){
    unsigned int i;
    for(i=0;i<20000;i++);
}

void main(){
    TRISB = 0x00;
    led = 0x80;

    while(1){
        led = led >> 1;
        if(led == 0x00){
            led = 0x80;
        }
        delay();
    }
}
