#include "str.h"


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