#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");

    int i = 2>3;
    


    printf("**********************************\n");
    int a;
    scanf("%d",&a);
    switch (a/10)
    {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    /* case a<90 && a>80:
        printf("B\n");
        break; */
    default:
        break;
    }


    printf("end\n");
    system("pause");
    return 0;
}