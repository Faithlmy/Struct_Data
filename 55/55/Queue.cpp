#include "lmy.h"

typedef struct Queue    //��ʽ���У�
{
	struct LNode *rear;
	struct LNode *front;
}SqQueue;
typedef struct        //˳�����
{
	ElemType *base;
	int front;
	int rear;
}SqQueueCir;
typedef struct{   //�����������ѭ�����У�

	ElemType *base;
	int front;
	int rear;
	int temp;          //��¼��һ�е�rear����ȷ�����ӵĽ�����
}SqQueueCirl;