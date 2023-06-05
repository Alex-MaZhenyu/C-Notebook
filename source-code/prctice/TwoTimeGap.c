#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");





    // printf("**********************************\n");
    int hour1,minute1,hour2,minute2;
    printf("input first hour:");
    scanf("%d",&hour1);
    printf("input minute:");
    scanf("%d",&minute1);
    printf("input second hour:");
    scanf("%d",&hour2);
    printf("input minute:");
    scanf("%d",&minute2);


    printf("the tow time gap is : %d minutes\n;",(hour1*60+minute1)-(hour2*60+minute2));

    double h,m;
    h  = ((hour1*60+minute1)-(hour2*60+minute2)) / 60;
    m  = ((hour1*60+minute1)-(hour2*60+minute2)) % 60;


    printf("the tow time gap is : %.2f hours %.2f minutes\n;",h,m);

    printf("end\n");
    system("pause");
    return 0;
}   