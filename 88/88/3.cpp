#include "stdio.h"  

#define OK 1  
#define ERROR 0  
#define TRUE 1  
#define FALSE 0  

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node *LinkList; /* 定义LinkList */

Status visit(ElemType c)
{
	printf("->%d", c);
	return OK;
}

/* 初始化顺序线性表 */
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) /* 存储分配失败 */
		return ERROR;
	(*L)->next = NULL; /* 指针域为空 */

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

LinkList SelectSort2(LinkList L)
{
	LinkList p, q, small;
	int temp;

	for (p = L->next; p->next != NULL; p = p->next)
	{
		small = p;
		for (q = p->next; q; q = q->next)
		{
			if (q->data < small->data)
			{
				small = q;
			}
		}
		printf("循环后，获得最小值为:%d, 此时链表为:", small->data);
		if (small != p)
		{
			temp = p->data;
			p->data = small->data;
			small->data = temp;
		}
		ListTraverse(L);
	}
	printf("输出排序后的数字:\n");
	return L;
}

LinkList SelectSort(LinkList L)
{
	LinkList first;     /*排列后有序链的表头指针*/
	LinkList tail;      /*排列后有序链的表尾指针*/
	LinkList p_min;     /*保留键值更小的节点的前驱节点的指针*/
	LinkList min;       /*存储最小节点*/
	LinkList p;         /*当前比较的节点*/

	first = NULL;
	while (L != NULL) /*在链表中找键值最小的节点。*/
	{
		/*注意：这里for语句就是体现选择排序思想的地方*/
		for (p = L, min = L; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
		{
			if (p->next->data < min->data) /*找到一个比当前min小的节点。*/
			{
				p_min = p; /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
				min = p->next; /*保存键值更小的节点。*/
			}
		}

		/*上面for语句结束后，就要做两件事；
		一是把它放入有序链表中；
		二是根据相应的条件判断，安排它离开原来的链表。*/

		/*第一件事*/
		if (first == NULL) /*如果有序链表目前还是一个空链表*/
		{
			first = min; /*第一次找到键值最小的节点。*/
			tail = min; /*注意：尾指针让它指向最后的一个节点。*/
		}
		else /*有序链表中已经有节点*/
		{
			tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
			tail = min; /*尾指针也要指向它。*/
		}
		/*第二件事*/
		if (min == L) /*如果找到的最小节点就是第一个节点*/
		{
			//printf("表头%d已经是最小，当前结点后移。\n", min->data);  
			L = L->next; /*显然让head指向原head->next,即第二个节点，就OK*/
		}
		else /*如果不是第一个节点*/
		{
			p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
		}
	}
	if (first != NULL) /*循环结束得到有序链表first*/
	{
		tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/
	}
	L = first;
	return L;
}

int main()
{
	LinkList L;
	Status i;
	char opp;
	ElemType e;
	int find;
	int tmp;

	i = InitList(&L);
	printf("初始化L后：ListLength(L)=%d\n", ListLength(L));

	printf("\n1.查看链表 \n2.创建链表（尾插法） \n3.链表长度 \n4.交换两个结点 \n0.退出 \n请选择你的操作：\n");
	while (opp != '0')
	{
		scanf("%c", &opp);
		switch (opp)
		{
		case '1':
			ListTraverse(L);
			printf("\n");
			break;

		case '2':
			CreateListTail(&L, 10);
			printf("整体创建L的元素(尾插法)：\n");
			ListTraverse(L);
			printf("\n");
			break;

		case '3':
			//clearList(pHead);   //清空链表  
			printf("ListLength(L)=%d \n", ListLength(L));
			printf("\n");
			break;

		case '4':
			L = SelectSort2(L);
			//printf("%d \n", find);  
			ListTraverse(L);
			printf("\n");
			break;

		case '0':
			exit(0);
		}
	}
}