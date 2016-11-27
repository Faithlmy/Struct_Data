#include "lmy.h"
#include "Queue.cpp"
void Create(SqQueueCirl &q)
{
	q.base = (ElemType*)malloc(10 * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.base[0] = 0;
	q.base[1] = 1; //ѭ�����еĵ�һ��Ԫ�ش�Ϊ1
	q.temp = q.rear = 2;//��ͷ�����ָ��ָ��ڶ���Ԫ�ص�λ��
	q.front = 1;
}
void Init(SqQueueCirl &q)
{
	if ((q.rear + 1) % 10 == q.front)
	{
		cout << "������";
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
		}//�����һ�е�iʱ��������һ�е�Ԫ��;
		q.base[(q.temp + 9) % 10] = 0;
		cout << endl;
		q.base[q.rear] = 1;
		q.rear = (q.rear + 1) % 10;
		q.temp = q.rear;
		k = (i - 1) * 2;
	}
}