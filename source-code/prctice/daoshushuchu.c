#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a;
    printf("begin\n");
    printf("**********************************\n");
    scanf("%d",&a);

    int c = a/100; //得到最高位
    int d = (a%100)/10; //得到十位
    int e = a%10; //得到个位

    printf("the daoxu shu is %d\n",e*100+d*10+c);
    printf("end\n");
    system("pause");
    return 0;
}