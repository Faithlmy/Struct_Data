#include "str.h"

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
