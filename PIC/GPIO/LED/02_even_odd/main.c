#include <pic.h>

#define led PORTB

void delay(){
    unsigned int i,j;
    for(i=0;i<1000;i++){
        for(j=0;j<10;j++);
    }
}

void main(){
    unsigned int i;
    TRISB = 0x00;
    led = 0x00;

    while(1){
        for(i=0;i<8;i+=2){
            led = (1<<i);
            delay();
        }
        led = 0x00;
        for(i=1;i<8;i+=2){
            led = (1<<i);
            delay();
        }
        led = 0x00;
    }
}
