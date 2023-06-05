#include <stdio.h>
#include <stdlib.h>

int transfer(int *a, int *b){

    *a = 100;
    *b = 200;

    return 0;
}



int main(){

    printf("begin\n");


    int a = 10;
    int b = 20;
    printf("the address of a is %x;\n the address of b is %x;\n",&a,&b);

    printf("%d , %d \n",a,b);
 
    transfer(&a , &b);

    printf("%d , %d \n",a,b);





    printf("end\n");
    system("pause");
    return 0;
}