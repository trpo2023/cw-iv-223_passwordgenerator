#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <sys/errno.h>

void main(){
    int buf[256];
    int result = getrandom(buf,256,GRND_NONBLOCK);
    if(result<0){
        printf("failed.\n");
        printf("Error thrown: %d\n",errno);
    }
    else
    {
        printf("number of bytes read: %d\n",result);
    }   
    //sum the buffer, does this compromise the randomness? or does it help prevent predictability?
    result = 0;
    for(int i =0;i<256;i++){
        result += buf[i];
    }

    srand(result);
    printf("%d %d\n",result,rand()%59);
}