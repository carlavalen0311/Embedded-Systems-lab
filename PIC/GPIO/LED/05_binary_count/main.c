#include <pic.h>

void delay(unsigned int x){
    unsigned int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<1275;j++);
    }
}

void main(){
    unsigned int i;
    TRISB = 0x00;

    while(1){
        for(i=0;i<256;i++){
            PORTB = i;
            delay(20);
        }
    }
}
