#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");
    printf("**********************************\n");
    int month,week,day,year,totall;

    printf("Input the year: ");
    scanf("%d",&year);
    printf("Input the month:");
    scanf("%d",&month);
    printf("input the day: ");
    scanf("%d",&day);

    switch (month)
    {
    case 1:
        totall =  day ;
        break;
    case 2:       
        totall = 31 +  day;
        break;
    case 3:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 29 + day;
        else
            totall = 31 + 28 + day;
        break;
    case 4:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 29 + 31 + day;
        else
            totall = 31 + 28 + 31 + day;
        break;
    case 5:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 29 + 31 + 30 + day;
        else
            totall = 31 + 28 + 31 + 30 + day;
        break;
    case 6:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 29 + 31 + 30 + 31 + day;
        else
            totall = 31 + 28 + 31 + 30 + 31 + day;
        break;
    case 7:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + day;
        break;
    case 8:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
        break;
    case 9:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
        break;
    case 10:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
        break;
    case 11:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
        break;
    case 12:
        if(( (year/4 == 0) && (year/100 != 0))  ||  (year/400 == 0))
            totall = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
        else
            totall = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
        break;
    default:
        break;
    }
    if(totall%7 == 0)
        printf("this week is %dth week in 7th day;\n",totall/7);
    else
        printf("this week is %dth week in %dth day;\n",totall/7,totall%7);
    printf("end\n");
    system("pause");
    return 0;
}