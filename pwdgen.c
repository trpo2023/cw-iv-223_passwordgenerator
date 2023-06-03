#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <sys/random.h>
#include <sys/errno.h>

#define usage 
#define MAX 40

const char list[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                        'w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
                        'W','X','Y','Z','@','!','#','$','%','&','*','(',')','-','_','=','+','[',']','{','}','<','>','?',
                        '|','~','`','0','1','2','3','4','5','6','7','8','9'};

int * is_sequential(char str[],int str_length);

void main(int argc, char *argv[]){

    int i=0;
    int list_sz = ((int)sizeof(list)/sizeof(list[0]));
    int length,midpoint,rval,options;
    int l_flag = 0,s_flag = 0, unrecognized=0;
    int * sequence;
    int seed_bank[256];

    if(argc > 4){
        printf(error1);
        return;
    }
    else{   
        while(--argc>0 && (*++argv)[0] == '-'){
            
            while(options = *++argv[0]){
                switch (options)
                {
                    case 'l':
                        l_flag = 1;
                        if(argc > 1){
                            length = atoi(argv[1]);
                        }
                        if(length > MAX){
                            printf("Defaulting to %d for length. you tried: %d\n",MAX,length);
                            length = MAX;
                        }
                        else if(length == 0){
                            printf("Invalid length entry, defaulting to length 12\n");
                            length = 12;
                        }
                        break;  
                    case 's':
                        s_flag = 1;
                        break;
                    default:
                        printf("unrecognized option:> %c\n",options);
                        printf(usage);
                        unrecognized=1;
                        break;
                }
            };
        }
    }   
    if(unrecognized == 1){
        return;
    }
    else if(l_flag == 0){        
        length = 12;
    }

    char password[length];
    int seed = getrandom(seed_bank,256,GRND_NONBLOCK);
    if(seed<0){
        switch (errno)
        {
            case 11:
                printf("Error 'EAGAIN'\n");
                break;
            case 14:
                printf("Error 'EFAULT'\n");
                break;
            case 4:
                printf("Error 'EINTR'\n");
                break;
            case 38:
                printf("Error 'ENOSYS'\n");
                break;
            default:
                printf("Uncommon seed error. Errno: %d",errno);
                break;
        }
        return;
    }

    srand(seed_bank[0]);

    if(length % 2 != 0){
        midpoint = length/2 + 1;
    }
    else
    {
        midpoint = length/2;
    }   

    for(i=0;i<midpoint;i++){
        
        password[i] = list[rand() % list_sz];

        seed = getrandom(seed_bank,256,GRND_NONBLOCK);
        srand(seed_bank[0]);

        password[length-i-1] = list[rand() % list_sz];

        seed = getrandom(seed_bank,256,GRND_NONBLOCK);
        srand(seed_bank[0]);
    }  
    if(s_flag){
        while(s_flag){
            int fin_ctr = 0;   

            sequence = is_sequential(password,length); 

            for(int j =0;j<length;j++){
                if(sequence[j] == 1){                 
                    password[j] = list[rand() % list_sz];
                    fin_ctr++; 
                    srand(seed_bank[j]);       
                }
            }
            if(fin_ctr == 0){
                s_flag = 0;
            }          
        }
        free(sequence);        
    }
    for(i=0;i<length;i++){
        printf("%c",password[i]);
    }    
    printf("\n");
    return;
}

int * is_sequential(char str[],int str_length){
    int i,j=0;
    int * indices = malloc(sizeof(int) * str_length);

    for(i=0;i<str_length;i++){
        if(str[i] == str[i+1]){
            indices[i]=1;
            j++;
        }
        else
        {
            indices[i] = 0;
        }       
    }
    
    return indices;
}
