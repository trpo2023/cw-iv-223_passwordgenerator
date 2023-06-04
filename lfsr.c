#include <stdio.h>
#include <stdint.h>

void main(){

    //non zero starting seed
    int16_t start_seed = 0x0111;
    //seed the LFSR, must start different than seed for while()
    int16_t LFSR = start_seed + 0x0001;

    int counter = 0;

    while(LFSR!=start_seed){

        //'Taps' are placed at bit positions 7,9,13 of a 16bit input
        LFSR ^= LFSR >> 7;  
        LFSR ^= LFSR << 9;
        LFSR ^= LFSR >> 13;     
        
        counter++;
    }
    printf("%d\n",counter);
}