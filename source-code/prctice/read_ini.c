#include <stdio.h>
#include <stdlib.h>
int read_ini(char[]);
 int main() {

    char path[] =  "C:\\Users\\mazhenyu\\Documents\\C-Notebook\\source-code\\config\\mps08.ini";
    read_ini(path);

}

int read_ini(char filePath[] ){
    
    if(filePath == NULL){
        printf("filePath is null!\n"); 
        return -1;      
    }
    else{
        FILE *fp;
        char line[100];
        char section[100], key[100], value[100];
            // Open the .ini file
            FILE *test = NULL;
        fp = fopen(filePath, "r");
            // Read each line of the file
        if( (fp=fopen(filePath,"rb")) == NULL ){
            printf("Fail to open file!\n");
            system("pause");
            exit(0);  //退出程序（结束程序）
        }       
        while (fgets(line, 100, fp) != NULL) {
            // Check if the line is a section header
            if (sscanf(line, "[%[^]]", section) == 1) {
                printf("Section: %s\n", section);
            }
            // Check if the line is a key-value pair
            else if (sscanf(line, "%[^=]=%[^\n]", key, value) == 2) {
                printf("Key: %s, Value: %s\n", key, value);
            }
        }
            // Close the .ini file
        fclose(fp);
        system("pause");
            return 0;
    }
}