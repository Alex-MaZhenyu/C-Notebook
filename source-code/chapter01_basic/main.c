#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    return 0;

}

void youxianji(){

    printf("begin\n");
    printf("**********************************\n");
    int a =4, b=2;
    printf("a*=b+2 = %d\n",a*=b+2); //先算b+2
    printf("end\n");
    system("pause");
}

int const_basic(){

    printf("begin\n");
    const int AMOUNT = 100;
    printf("**********************************\n");
    printf("end\n");
    system("pause");
    return 0;
}

void operating_basic(){

    printf("begin\n");
    printf("**********************************\n");
    int a = 1;
    int b = 2;
    printf("a*-b = %d\n", a*-b);// a*-b 的意思是 a乘以负b，言下之意，将b取反的运算级别更高
    printf("end\n");
    system("pause");

/*     begin
       **********************************
       a*-b = -2
       end
       请按任意键继续. . . */
}
void printf_basic (){

    printf("begin\n");
    char c1[] = {'a','b','c','d'};
    printf("%.2s\n",c1);//从左往右只输出两个字符
    printf("end\n");
    system("pause");
    return 0;
}

void scanf_basic(){

    printf("begin\n");
    int  practice,amount,money;
    
/*     int i = 10;
    printf("%f\n",i); */   /* 这样只会输出0.00000，1、printf函数不进行任何类型转换，
    它只是从内存中读出你所提供的元素的值（按照%d，%f等控制字符提示的格式）。
    int型以补码形式存储在内存中，而浮点型是按照指数形式存储的。
 */
    printf("palease enter the amount:");
    scanf("%d", &amount);
    printf("palease enter the practice:");
    scanf("%d",&practice);
    int _temp = amount*practice;
    printf("you need to pay: %f\n",amount*practice);
    printf("**********************************\n");
    char c[20];
    scanf("input %s", c); 
    printf("you input %s\n",c);
    printf("end\n");
    system("pause");
    return 0;   
}