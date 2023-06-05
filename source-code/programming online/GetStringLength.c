#include <stdio.h>
#include <stdio.h>


int main() {

    char str[100] = { 0 };
    

    scanf("%s",&str);
    printf("%d",sizeof(str)/sizeof(str[0]));

    printf("end\n");
    system("pause");
    // write your code here......
    

    return 0;
}