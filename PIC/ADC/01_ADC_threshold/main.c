#include <pic.h>

#define rs RC5
#define rw RC6
#define e  RC7
#define lcd PORTD

#define HIGH_LED RC1
#define LOW_LED  RC0

void delay(unsigned int x){
    unsigned int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<1275;j++);
    }
}

void cmd(unsigned int c){
    lcd = c;
    rs = 0;
    rw = 0;
    e = 1;
    delay(2);
    e = 0;
}

void dat(unsigned int d){
    lcd = d;
    rs = 1;
    rw = 0;
    e = 1;
    delay(2);
    e = 0;
}

void init(){
    cmd(0x38);
    cmd(0x0C);
    cmd(0x06);
    cmd(0x01);
}

void number(unsigned int num){
    char s[5];
    int i = 0;

    if(num == 0){
        dat('0');
        return;
    }

    while(num > 0){
        s[i++] = (num % 10) + '0';
        num /= 10;
    }

    while(i--){
        dat(s[i]);
    }
}

void main(){
    unsigned int value;

    ADCON0 = 0x41;
    ADCON1 = 0xCE;

    TRISA = 0x01;
    TRISC = 0x00;
    TRISD = 0x00;

    PORTC = 0x00;
    PORTD = 0x00;

    init();

    while(1){
        ADCON0 |= 0x04;
        while(ADCON0 & 0x04);

        value = (ADRESH << 8) | ADRESL;

        cmd(0x01);
        cmd(0x80);
        number(value);

        if(value < 512){
            LOW_LED = 1;
            HIGH_LED = 0;
        } else {
            LOW_LED = 0;
            HIGH_LED = 1;
        }

        delay(50);
    }
}
