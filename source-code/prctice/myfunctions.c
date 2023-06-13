#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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

 /* 
    *将变量输出到指定的txt文件中
    * @param filename 文件名字符串
    * @param filepath 文件存放路径
    * @param format 格式化字符串，类似于printf函数中的格式化字符串，用于指定输出的变量类型和数量
    * @param ... 可变参数列表，用于传入需要输出的变量
    * @return 成功输出返回0，否则返回-1
 */
 int output_to_txt(char* filename, char* filepath, const char* format, ...) {
    FILE* fp;
    char fullpath[100];
    sprintf(fullpath, "%s/%s.txt", filepath, filename);
    fp = fopen(fullpath, "a");
    if (fp == NULL) {
        return -1;
    }
    va_list args;
    va_start(args, format);
    vfprintf(fp, format, args);
    va_end(args);
    fclose(fp);
    return 0;
}


#define MAX_LINE_LENGTH 256
#define MAX_TEST_NUM 100

 typedef struct {
    char test_name[MAX_LINE_LENGTH];    // 测试名称
    char load_condition[MAX_LINE_LENGTH];    // 负载条件
    char test_content[MAX_LINE_LENGTH];    // 测试内容
    double upper_limit;    // 上限
    double lower_limit;    // 下限
    char power_condition[MAX_LINE_LENGTH];    // 电源条件
    char comment[MAX_LINE_LENGTH];    // 备注
} TestCondition;


 void parse_test_conditions(const char* file_path) {
    FILE* fp = fopen(file_path, "r");    // 打开文件
    if (!fp) {
        printf("Failed to open file: %s\n", file_path);    // 打开文件失败
        return;
    }
     TestCondition test_conditions[MAX_TEST_NUM];    // 定义测试条件数组
    int num_test_conditions = 0;    // 测试条件数量
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {    // 逐行读取文件内容
        if (num_test_conditions >= MAX_TEST_NUM) {
            printf("Too many test conditions, max supported: %d\n", MAX_TEST_NUM);    // 测试条件数量超过最大值
            break;
        }

        char* token = strtok(line, "\t");    // 使用制表符分割每行内容
       
        if (!token) { 
            printf("Invalid test condition: %s\n", line);    // 无效的测试条件
            continue;
        }


        token = strtok(NULL, "\t");
        strcpy(test_conditions[num_test_conditions].test_name, token);
        token = strtok(NULL, "\t");


        strcpy(test_conditions[num_test_conditions].load_condition, token);
        token = strtok(NULL, "\t");
        
        strcpy(test_conditions[num_test_conditions].test_content, token);
        token = strtok(NULL, "\t");
   
        test_conditions[num_test_conditions].upper_limit = atof(token);
        token = strtok(NULL, "\t");
    
        test_conditions[num_test_conditions].lower_limit = atof(token);
        token = strtok(NULL, "\t");
 
        strcpy(test_conditions[num_test_conditions].power_condition, token);

        token = strtok(NULL, "\t");
        if (token) {
            strcpy(test_conditions[num_test_conditions].comment, token);
        }


         num_test_conditions++;    // 测试条件数量加1
    }
     fclose(fp);    // 关闭文件
     for (int i = 0; i < num_test_conditions; i++) {
        printf("double %s[] = {0, %g, %g};\t\t//%s\n", 
               test_conditions[i].test_name, 
               test_conditions[i].lower_limit, 
               test_conditions[i].upper_limit, 
               test_conditions[i].comment);    // 输出测试条件数组
    }
}
 int main() {
    parse_test_conditions("test_conditions.txt");    // 调用函数，解析测试条件
    return 0;
}