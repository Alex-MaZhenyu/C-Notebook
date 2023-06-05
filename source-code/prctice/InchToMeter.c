#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");
    const double EFF = 0.3048;
    double meter;
    int inch,foot;

    printf("input the inch: ");
    scanf("%d",&inch);
    printf("foot: ");
    scanf("%d",&foot);
    meter = ( inch + foot / 12.0) * 0.3048;

    printf("The hight in Chinese is %f meter;\n", meter);

    printf("end\n");
    system("pause");
    return 0;
}