#include <stdio.h>//ͷ�ļ�����
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int val;
	struct node_s* next;

}Node;

Node* add_to_list(Node* list, int val);

int main()//������
{
	Node* head = NULL; // ����ͷ���Ľڵ㡣��ν�Ľڵ����һͷ���ṹ���ָ��
	head = add_to_list(head, 1);
	head = add_to_list(head, 2);
	head = add_to_list(head, 3);
	head = add_to_list(head, 4);







	system("pause");//��ͣ����
	return 0;//���ص�������
}

Node* add_to_list(Node* list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Error : malloc failed in add_to_list.\n");
		exit(1);
	}
	//ͷ�巨
	newNode->val = val;
	newNode->next = list;

	return newNode;
}