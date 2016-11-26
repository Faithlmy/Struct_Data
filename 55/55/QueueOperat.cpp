#include"str.h"

void Create_Sq(SqQueueCir &q)
{
	q.base = (ElemType*)malloc(MAX * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.front = q.rear = 0;
}
void InitQueue_Sq(SqQueueCir &q)//Èë¶Ó
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