#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int time01,time02,hour01,minute01,hour02,minute02,gap;
    printf("begin\n");
    printf("**********************************\n");
    scanf("%d %d",&time01,&time02);

    minute01 = (time01 % 100);  //后两位
    minute02 = (time02 % 100);  //后两位

    hour01 = time01/100 ;
 /*   hour02 = time02/100 ; 

    gap = hour01*60+minute01 + (hour02*60+minute02);
 */

    int h = time02/60;  // 得到小时数
    int m = time02%60;  // 得到分钟数

    int h01 =  (minute01 + m)/60;  // 分钟大于60 ，得到进位
    int m01 =  (minute01 + m)%60;  // gap分钟数

    hour01 = (hour01 + h01 + h) % 24;
    
    printf("now is %d\n",(hour01)*100 + m01);

    printf("end\n");
    system("pause");
    return 0;
}
