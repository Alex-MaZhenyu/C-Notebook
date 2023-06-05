#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");
    printf("**********************************\n");
    int i;
    scanf("%d",&i);
    char c[10];
    c[0] =  i/1000;
    c[1] = i/100;
    c[2] = i/10;
    c[3] = i%10;

    if(c[0]>0){
        printf("4\n");
    }else if(c[1]>0){
        printf("3\n");
    }else if(c[2]>0){
        printf("2\n");
    }else if(c[3]>=0){
        printf("1\n");
    }else{
        printf("0\n");
    }

/*     switch (c)
    {
    case '1':
      
        break;
    
    default:
        break;
    } */

    printf("end\n");
    system("pause");
    return 0;
}