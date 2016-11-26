#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100       //栈，循环队列的最大值；
#define OVERFLOW -1

using namespace std;

typedef int ElemType;
typedef int Status;
typedef struct Stack   //顺序栈；
{
	ElemType *base;
	ElemType *top;
}SqStack;
typedef struct LNode    //链式栈的结点； 
{
	ElemType data;
	struct LNode *next;
};
typedef struct LqStack  //链式栈；
{
	struct LNode *base;
	struct LNode *top;
};
typedef struct Queue    //链式队列；
{
	struct LNode *rear;
	struct LNode *front;
}SqQueue;
typedef struct        //顺序队列
{
	ElemType *base;
	int front;
	int rear;
}SqQueueCir;
typedef struct{   //杨辉三角特殊循环队列；

	ElemType *base;
	int front;
	int rear;
	int temp;          //记录上一行的rear，以确定出队的结束；
}SqQueueCirl;
void CreateLq(LqStack &s)   //链式栈的构建；
{
	s.top = (LNode*)malloc(sizeof(LNode));
	s.top->next = NULL;
}
void LqPush(LqStack &s)      //链式栈的入栈；
{
	LNode *p;
	cin >> s.top->data;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = s.top;  //....
	s.top = p;
}
ElemType LqGetTop(LqStack s)
//链式栈的出栈，返回一个ElemT类型；数，并释放此结点。
{
	LNode *p;
	ElemType e;
	p = s.top->next;
	e = p->data;
	s.top->next = p->next;
	free(p);
	return e;
}
void CreateSq(SqStack &s)        //顺序栈初始化;
{
	s.base = (ElemType *)malloc(MAX*sizeof(ElemType));
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
}
void Push(SqStack &s, ElemType e)   //顺序栈入栈;
{
	if ((s.top - s.base)>MAX || (s.top - s.base) == MAX)
		exit(OVERFLOW);
	*(s.top) = e;
	s.top++;
}
ElemType GetTop(SqStack &s)       //顺序栈出栈;
{
	ElemType e;
	if (s.top == s.base)//判断栈空;
		cout << "栈为空！" << endl;
	e = *(s.top - 1);
	s.top--;
	return e;
}
void InitQueue(SqQueue &Q)      //链式队列的初始化;
{
	Q.rear = (LNode*)malloc(sizeof(LNode));
	if (!Q.rear)exit(OVERFLOW);//判断是否成功开辟空间;
	Q.front = Q.rear;
	Q.front->next = NULL;
}
void EnQueue(SqQueue &Q)   //链式队列的入队;
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)exit(OVERFLOW);
	cin >> p->data;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
ElemType PoQueue(SqQueue &Q)//链式队列的出队;
{
	LNode *p;
	ElemType e;
	if (Q.rear == Q.front)exit(OVERFLOW);
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return e;
}
void Create_Sq(SqQueueCir &q)
{
	q.base = (ElemType*)malloc(MAX * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.front = q.rear = 0;
}
void InitQueue_Sq(SqQueueCir &q)//入队
{
	if ((q.rear + 1) % MAX == q.front)exit(OVERFLOW);
	cin >> q.base[q.rear];
	q.rear = (q.rear + 1) % MAX;
}
ElemType DeQueue_Sq(SqQueueCir &q)
{
	if (q.front == q.rear)exit(OVERFLOW);
	ElemType e = q.base[q.front];
	q.front = (q.front + 1) % MAX;
	return e;
}
void Menu()
{
	cout <<"按数字键选择相应操作\n";
	cout << "<1> 采用链式存储实现栈的初始化、入栈、出栈操作:\n";
	cout << "<2> 采用顺序存储实现栈的初始化、入栈、出栈操作:\n";
	cout << "<3> 采用链式存储实现队列的初始化、入队、出队操作\n";
	cout << "<4> 采用顺序存储实现循环队列的初始化、入队、出队操作:\n";
	cout << "<5> 利用栈实现数制转换（将一个十进制数转换成d进制数）:\n";
	cout << "<6> 利用队列打印8行杨辉三角：编写程序，根据输入的行数，屏幕显示8行杨辉三角:\n";
	printf("<0> 退出:\n");
}
void conversion()
{
	SqStack s;
	CreateSq(s);
	cout << "请输入需转换进制元素：";
	ElemType e, n;
	cin >> e;
	cout << "请输入转换成多少进制的权：";
	cin >> n;
	while (e)
	{
		Push(s, e%n);
		e = e / n;
	}
	while (s.base != s.top)
	{
		cout << GetTop(s);
	}
	cout << "(" << n << ")";
	cout << endl;
}
void Create(SqQueueCirl &q)
{
	q.base = (ElemType*)malloc(10 * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.base[0] = 0;
	q.base[1] = 1; //循环队列的第一个元素存为1;
	q.temp = q.rear = 2;//对头和输出指针指向第二个元素的位置;
	q.front = 1;
}
void Init(SqQueueCirl &q)
{
	if ((q.rear + 1) % 10 == q.front)
	{
		cout << "队列满";
		exit(OVERFLOW);
	}
	q.base[q.rear] = q.base[(q.front + 9) % 10] + q.base[q.front];
	q.rear = (q.rear + 1) % 10;
}
ElemType DeQueue_Sq(SqQueueCirl &q)
{
	if (q.front == q.rear)exit(OVERFLOW);
	ElemType e = q.base[q.front];
	q.front = (q.front + 1) % 10;
	return e;
}
void PascalTriangle()
{
	SqQueueCirl q;
	Create(q);
	int i = 8, k = 14;
	while (i--)
	{
		while (k--)
			cout << " ";
		while (q.front != q.temp)
		{
			Init(q);
			cout << DeQueue_Sq(q) << "   ";
		}//输出上一行的i时，存入下一行的元素;
		q.base[(q.temp + 9) % 10] = 0;
		cout << endl;
		q.base[q.rear] = 1;
		q.rear = (q.rear + 1) % 10;
		q.temp = q.rear;
		k = (i - 1) * 2;
	}
}
int main()
{
	int m, e, n;
	while (1)
	{
		Menu();
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "请输入需入栈元素个数：";
			LqStack head;
			CreateLq(head);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				LqPush(head);
			cout << "入栈完成！" << endl;
			while (head.top->next != NULL)
			{
				cout << LqGetTop(head) << "  ";
			}
			cout << endl;
			cout << "出栈完成！" << endl;
			break;
		case 2:
			cout << "请输入需入栈元素个数：";
			SqStack s;
			CreateSq(s);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
			{
				cin >> e;
				Push(s, e);
			}
			cout << "入栈完成！" << endl;
			while (s.base != s.top)
			{
				cout << GetTop(s) << "  ";
			}
			cout << endl;
			cout << "出栈完成！" << endl;
			break;
		case 3:
			cout << "请输入需入队元素个数：";
			SqQueue Q;
			InitQueue(Q);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				EnQueue(Q);
			cout << "入队完成！" << endl;
			while (Q.front != Q.rear)
			{
				cout << PoQueue(Q) << "  ";
			}
			cout << endl;
			cout << "出队完成！" << endl;
			break;
		case 4:
			cout << "请输入需入队元素个数：";
			SqQueueCir h;
			Create_Sq(h);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				InitQueue_Sq(h);
			cout << "入队完成！" << endl;
			while (h.front != h.rear)
			{
				cout << DeQueue_Sq(h) << "  ";
			}
			cout << endl;
			cout << "出队完成！" << endl;
			break;

		case 5:
			conversion();
			break;

		case 6:
			PascalTriangle();
			break;

		case 0:
			exit(OVERFLOW);
		default:
			cout << "输入错误，请重新输入：" << endl;
			break;
		}
	}
	return 0;
}
