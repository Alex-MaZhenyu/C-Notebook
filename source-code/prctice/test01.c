 #include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
 


#define MAX_LINE_LENGTH 256
#define MAX_TEST_NUM 100


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
    sprintf(fullpath, "%s\\%s.txt", filepath, filename);
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

typedef struct {
    char test_name[MAX_LINE_LENGTH];    // 测试名称
    char load_condition[MAX_LINE_LENGTH];    // 负载条件
    char test_content[MAX_LINE_LENGTH];    // 测试内容
    double upper_limit;    // 上限
    double lower_limit;    // 下限
    char power_condition[MAX_LINE_LENGTH];    // 电源条件
    char comment[MAX_LINE_LENGTH];    // 备注
} TestCondition;

int parse_test_conditions(const char* read_filename, const char* read_filepath, const char* write_filename, const char* write_filepath) {
    int a = strlen(read_filename)+strlen(read_filepath);
    //char read_file_path[MAX_LINE_LENGTH];
    char read_file_path[a+5];
    strcpy(read_file_path, read_filepath);
    strcat(read_file_path, read_filename);
    strcat(read_file_path, ".txt");


    FILE* fp = fopen(read_file_path, "r");    // 打开文件
    if (!fp) {
        printf("Failed to open file: %s\n", read_file_path);    // 打开文件失败
        return -1;
    }

    TestCondition test_conditions[MAX_TEST_NUM];    // 定义测试条件数组
    int num_test_conditions = 0;    // 测试条件数量

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp)) {    // 逐行读取文件内容
        if (num_test_conditions >= MAX_TEST_NUM) {
            printf("Too many test conditions, max supported: %d\n", MAX_TEST_NUM);    // 测试条件数量超过最大值
            fclose(fp);
            return -1;
        }
        printf(line);
        char* token = strtok(line, "\t");    // 使用制表符分割每行内容, 返回值token 是指向下一个字符串的指针
        if (!token) {
            printf("Invalid test condition: %s\n", line);    // 无效的测试条件
            continue;
        }
        strcpy(test_conditions[num_test_conditions].test_name, token);
         token = strtok(NULL, "\t");
        if (!token) {
            printf("Invalid test condition: %s\n", line);
            continue;
        }
        strcpy(test_conditions[num_test_conditions].load_condition, token);
         token = strtok(NULL, "\t");
        if (!token) {
            printf("Invalid test condition: %s\n", line);
            continue;
        }
        strcpy(test_conditions[num_test_conditions].test_content, token);
         token = strtok(NULL, "\t");
        if (!token) {
            printf("Invalid test condition: %s\n", line);
            continue;
        }
        test_conditions[num_test_conditions].upper_limit = atof(token);
         token = strtok(NULL, "\t");
        if (!token) {
            printf("Invalid test condition: %s\n", line);
            continue;
        }
        test_conditions[num_test_conditions].lower_limit = atof(token);
         token = strtok(NULL, "\t");
        if (!token) {
            printf("Invalid test condition: %s\n", line);
            continue;
        }
        strcpy(test_conditions[num_test_conditions].power_condition, token);
         token = strtok(NULL, "\t");
        if (token) {
            strcpy(test_conditions[num_test_conditions].comment, token);
        }

        num_test_conditions++;    // 测试条件数量加1
    }

    fclose(fp);    // 关闭文件
    int b = strlen(write_filepath)+strlen(write_filename);
    char write_file_path[b+5];

    strcpy(write_file_path, write_filepath);
    strcat(write_file_path, write_filename);
    strcat(write_file_path, ".txt");

    FILE* output_fp = fopen(write_file_path, "w");


    if (!output_fp) {
        printf("Failed to open output file: %s\n", write_file_path);
        return -1;
    }

    for (int i = 0; i < num_test_conditions; i++) {
        fprintf(output_fp, "double %s[] = {0, %g, %g};\t\t//%s\n",
                test_conditions[i].test_name,
                test_conditions[i].lower_limit,
                test_conditions[i].upper_limit,
                test_conditions[i].comment);    // 输出测试条件数组到txt文件
    }

    fclose(output_fp);    // 关闭输出文件

    return 1;
}

int main() {

    /* char read_file_name[] = "TLP0124FPMCZ01A Limit";
    char filepath[] = "C:\\Users\\mazhenyu\\Desktop"; */
    const char* read_filename = "TLP0124FPMCZ01A";
    const char* read_filepath = "C:\\Users\\mazhenyu\\Desktop\\";
    const char* write_filename = "output";
    const char* write_filepath = "C:\\Users\\mazhenyu\\Desktop\\";

    int result = parse_test_conditions(read_filename, read_filepath, write_filename, write_filepath);



    if (result == 1) {
        printf("文件处理成功\n");
    } else {
        printf("文件处理失败\n");
    }

     system("pause");
    return 0;
}