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