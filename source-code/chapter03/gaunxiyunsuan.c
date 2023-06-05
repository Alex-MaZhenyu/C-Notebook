#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");
    printf("**********************************\n");

    printf("%d\n",6>5);// 6>5 为真，输出1；
    printf("%d\n",7>=6+2); // 关系运算低于加减运算，结果为0；


    printf("end\n");
    system("pause");
    return 0;
}