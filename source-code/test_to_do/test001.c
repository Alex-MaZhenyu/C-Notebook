#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("begin\n");
    printf("**********************************\n");

    char str[80] = "This is a string, with commas.,and then,it will?";
   const char s[2] = ",";
   char *token;

   /* 获取第一个子字符串 */
   token = strtok(str, s);

   /* 继续获取其他的子字符串 */
   while( token != NULL ) {
      printf( "%s\n", token );
      token = strtok(NULL, s);
   }

    printf("end\n");
    system("pause");
    return 0;
}