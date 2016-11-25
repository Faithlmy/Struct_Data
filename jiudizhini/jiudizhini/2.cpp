#include <stdio.h>  
#include <stdlib.h>  

typedef struct Node{
	int data;
	struct Node * next;
}Node, *LinkList;


void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void CreateList(LinkList L)
{
	int dt;
	Node *s;
	while (scanf_s("%d", &dt)){
		s = (Node *)malloc(sizeof(Node));
		s->data = dt;
		s->next = L->next;
		L->next = s;
	}
	//printf("create success\n");  
}

void ReverseList(LinkList L)
{
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
	void printList(LinkList L)
	{
		LinkList p;
		p = L->next;
		while (p != NULL){
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}

	int main()
	{
		LinkList list;
		InitList(&list);
		CreateList(list);
		printf_s("before reverse:\n");
		printList(list);
		ReverseList(list);
		printf_s("after reverse:\n");
		printList(list);
		return 0;
	}
