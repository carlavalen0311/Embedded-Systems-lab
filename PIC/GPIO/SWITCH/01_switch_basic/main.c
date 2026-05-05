#include <pic.h>

#define led RB0
#define sw RD0

void main(){
    TRISB0 = 0;
    TRISD0 = 1;

    while(1){
        if(sw == 1){
            led = 1;
        } else {
            led = 0;
        }
    }
}
