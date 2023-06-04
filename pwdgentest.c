#include <stdio.h>
#include <stdlib.h>

double combinations(int pool, int select);
double factorial(int value);

void main(){
    int choices,chosen;
    printf("enter the number of choices:> ");
    int result = scanf("%d",&choices);
    if(result<0){
        printf("\nMust enter an integer value. exiting..\n");
        return;
    }
    printf("enter the number to be chosen from pool of choices:> ");
    result = scanf("%d",&chosen);
    if(result<0){
        printf("\nMust enter an integer value. exiting..\n");
        return;
    }    
    if(chosen>choices){
        printf("number chosen is greater than the possible choices..exiting.\n");
        return;
    }
    
    printf("possible combinations: %.0f\n",combinations(choices,chosen));
}

double combinations(int pool,int select){
    return factorial(pool)/((factorial(select))*(factorial(pool - select)));
}

double factorial(int value){
    int i = 0;
    double answer = 1.;
    if(value > 170 || value <= 0){
        return 0;
    }
    for(i=1;i<value+1;i++){
        answer *= i;
    }
    return answer;
}