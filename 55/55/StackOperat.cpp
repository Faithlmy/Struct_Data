#include "str.h"


void LqPush(LqStack &s)      //��ʽջ����ջ��
{
	LNode *p;
	cin >> s.top->data;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = s.top;  //....
	s.top = p;
}

ElemType LqGetTop(LqStack s)
//��ʽջ�ĳ�ջ������һ��ElemT���ͣ��������ͷŴ˽�㡣
{
	LNode *p;
	ElemType e;
	p = s.top->next;
	e = p->data;
	s.top->next = p->next;
	free(p);
	return e;
}

void InitQueue(SqQueue &Q)      //��ʽ���еĳ�ʼ��;
{
	Q.rear = (LNode*)malloc(sizeof(LNode));
	if (!Q.rear)exit(OVERFLOW);//�ж��Ƿ�ɹ����ٿռ�;
	Q.front = Q.rear;
	Q.front->next = NULL;
}
void EnQueue(SqQueue &Q)   //��ʽ���е����;
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)exit(OVERFLOW);
	cin >> p->data;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
ElemType PoQueue(SqQueue &Q)//��ʽ���еĳ���;
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