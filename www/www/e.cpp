#include<stdio.h>  
#include<stdlib.h>  
#include"malloc.h"  
#include"queue.h"  
/***********************************************
Function: Create a empty stack;
************************************************/
void CreateQueue(PQUEUE Q, int maxsize)
{
	Q->pBase = (int *)malloc(sizeof(int)*maxsize);
	if (NULL == Q->pBase)
	{
		printf("Memory allocation failure");
		exit(-1);  //�˳�����  
	}
	Q->front = 0;  //��ʼ������  
	Q->rear = 0;
	Q->maxsize = maxsize;
}
/***********************************************
Function: Print the stack element;
************************************************/
void TraverseQueue(PQUEUE Q)
{
	int i = Q->front;
	printf("���е�Ԫ����:\n");
	while (i%Q->maxsize != Q->rear)
	{
		printf("%d ", Q->pBase[i]);
		i++;
	}
	printf("\n");
}
bool FullQueue(PQUEUE Q)
{
	if (Q->front == (Q->rear + 1) % Q->maxsize)    //�ж�ѭ�������Ƿ�������һ��Ԥ���ռ䲻��  
		return true;
	else
		return false;
}
bool EmptyQueue(PQUEUE Q)
{
	if (Q->front == Q->rear)    //�ж��Ƿ�Ϊ��  
		return true;
	else
		return false;
}
bool Enqueue(PQUEUE Q, int val)
{
	if (FullQueue(Q))
		return false;
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return true;
	}
}

bool Dequeue(PQUEUE Q, int *val)
{
	if (EmptyQueue(Q))
	{
		return false;
	}
	else
	{
		*val = Q->pBase[Q->front];
		Q->front = (Q->front + 1) % Q->maxsize;
		return true;
	}
}