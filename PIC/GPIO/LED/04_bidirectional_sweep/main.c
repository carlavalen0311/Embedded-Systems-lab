#include <pic.h>

#define led PORTB

void delay(){
    unsigned int i;
    for(i=0;i<10000;i++);
}

void main(){
    unsigned int i;
    TRISB = 0x00;
    led = 0x00;

    while(1){
        for(i=0;i<8;i++){
            led = 1<<i;
            delay();
            led = 0x80>>i;
            delay();
        }
    }
}
