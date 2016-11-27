#include "lmy.h"
#include "Queue.cpp"
void Create(SqQueueCirl &q)
{
	q.base = (ElemType*)malloc(10 * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.base[0] = 0;
	q.base[1] = 1; //循环队列的第一个元素存为1
	q.temp = q.rear = 2;//对头和输出指针指向第二个元素的位置
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