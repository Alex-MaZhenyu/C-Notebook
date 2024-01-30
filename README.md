# <center> C语言快速查询
**在这里首先鸣谢黑马教育全体教师及工作人员，让我能够免费享受这些资源；感谢浙大翁恺老师细致的讲解；还有 C Primer Plus的作者写出如此优秀的书籍！**

## 大纲

> 1. 本笔记规范
> 2. 第一章  编译与链接
> 3. 第二章  数据类型、运算符与表达式
> 4. 第三章  选择与循环
> 5. 第五章  数组
> 6. 第六章 指针
> 7. 结构体与链表
> 8. 常用数据结构与算法

## 本笔记规范

 - 写代码的时候不要开中文输入法  
 - 每一单元仅包含一个main函数;  
 - 练习每题均单独保存，需将题目保存在程序头部位置。

## 第一章 编译与链接

gcc -o hello.c ； 

预处理

编译

汇编

链接

## 第二章 


## 第三章判断：分支结构

if 语句
关系运算 == ， ！= ，>= , <=
    关系运算符的优先级小于加减，大于赋值 7>= 6+2; 为否
    5>4>3; 结果为0，从左到右运算
    a == b == 6;
嵌套if  else
    else是离它最上面的if;
级联 if-else if
    if
    else if
    else
switch-case    
    遇到break为止；
    case必须为常量；
    
## 循环
第五周：循环控制
第六周：数据类型和处理
第七周：函数
第八周：数组
第九周：指针
第十周：字符串
第十一周：结构类型
第十二周：程序结构
第十三周：链表
第十四周：文件



## 第五章 函数
### 目的：
    为了减少重复代码块、模块清晰。
### 定义形式：
    返回类型 函数名 （形参列表）
    {
        数据定义部分；
        执行语句部分；
        return；
    }
### 注意事项：
- 函数的定义不要放在代码块中（另一个函数里），
- 形参只有在调用时才会开辟空间，
- 函数有形参时候，必须传入参数。
- 调用函数时，（）里面的参数叫实参。**实参与形参类型保持一致就行**。
- return的解释：返回值小于等于4字节，返回寄存器。返回值大于4字节，返回内存。
- **实参的值传给形参后，实参不会被形参改变。**

### 函数声明：
    需要在调用之前声明函数，与变量一样。
    函数声明不强制要求extern； 
    函数声明形参可以只写类型void fun（int,int） 

### return 和 exit 区别
    return() 是结束当前函数；
    exit() 是库函数，结束整个程序，无论在子函数还是主函数，调用exit都会结束程序；
### 分文件编程
     采用头文件声明，再include头文件
     防止头文件多次包含
     #ifndef FILENAME_H
     #define FILENAME_H
     …（头文件内容）
     #endif
     C标准头文件使用#ifndef技巧避免重复包含。但是，这存在一个问题：如何确保待测试的标识符没有在别处定义。通常，实现的供应商使用这些方法解决这个问题：用文件名作为标识符、使用大写字母、用下划线字符代替文件名中的点字符、用下划线字符做前缀或后缀（可能使用两条下划线）。例如，查看stdio.h头文件，可以发现许多类似的代
     码：
     #ifndef _STDIO_H
     #define _STDIO_H
     // 省略了文件的内容
     #endif

或者 **#pragma once**

     需要注意的是，只有在大多数编译器中都支持该指令的情况下才能使用，因为并非所有的编译器都支持该指令。
    
     包含多个头文件时，其中的文件可能包含了相同宏定义。#ifndef
     指令可以防止相同的宏被重复定义。在首次定义一个宏的头文件中用#ifndef
     指令激活定义，随后在其他头文件中的定义都被忽略。

## 第六章 内存

    指针就是内存编号； 
    指针变量：存指针（地址）的变量，32位操作系统，指针类型p的大小为4字节。











## 第七章 结构体与链表





### 链表

```
单向链表：最后指向NULL
单向循环链表： 最后指向首部
双向链表：一个数据域两个指针域
```

```c
#include <stdio.h>//头文件引用
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int val;
	struct node_s* next;

}Node;

Node* add_to_list(Node* list, int val);

int main()//主函数
{
	Node* head = NULL; // 这是头部的节点。所谓的节点就是一头部结构体的指针
	head = add_to_list(head, 1);
	head = add_to_list(head, 2);
	head = add_to_list(head, 3);
	head = add_to_list(head, 4);

	system("pause");//暂停函数
	return 0;//返回到主程序
}

Node* add_to_list(Node* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Error : malloc failed in add_to_list.\n");
		exit(1);
	}
	//头插法
	newNode->val = val;
	newNode->next = list;

	return newNode;
}
```



---
遇到的问题以及解决的答案
1. ：vscode里"${fileDirname}\\${fileBasenameNoExtension}.exe",什么意思
这段代码是为了在VSCode中打开文件所在文件夹，并运行相应的.EXE文件。
${fileDirname}：表示当前打开文件所在的目录路径。
${fileBasenameNoExtension}：表示当前打开文件的文件名，不包含扩展名。
通过将这两个变量结合在一起，可以获得当前文件所在目录路径和文件名（不包含扩展名），然后在终端中运行相应的.EXE文件。
---
2. json报错.exe文件不存在。
   
   原因是发现编译生成可执行代码过程出现错误，不能生成exe文件，应该检查一下问题。
---





有关详细资料可以邮件联系我 [alexduck@qq.com](alexduck@qq.com). 
