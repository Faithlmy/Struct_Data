#include "lmy.h"

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