#include "lmy.h"
#include "Queue.cpp"
#include "Stack.cpp"

void InitQueue(SqQueue &Q)     //��ʽ���еĳ�ʼ��
{
	Q.rear = (LNode*)malloc(sizeof(LNode));
	if (!Q.rear)exit(OVERFLOW);//�ж��Ƿ�ɹ����ٿռ�
	Q.front = Q.rear;
	Q.front->next = NULL;
}
void EnQueue(SqQueue &Q) //��ʽ���е����;
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)exit(OVERFLOW);
	cin >> p->data;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
ElemType PoQueue(SqQueue &Q)//��ʽ���еĳ���
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
void InitQueue_Sq(SqQueueCir &q)//���
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