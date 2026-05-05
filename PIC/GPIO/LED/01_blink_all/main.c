#include <pic.h>

void delay(unsigned int x){
    unsigned int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<1275;j++);
    }
}

void main(){
    TRISB = 0x00;
    while(1){
        PORTB = 0xFF;
        delay(10);
        PORTB = 0x00;
        delay(10);
    }
}
