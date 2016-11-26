#include "str.h"

typedef struct Stack   //˳��ջ��
{
	ElemType *base;
	ElemType *top;
}SqStack;
typedef struct LNode    //��ʽջ�Ľ�㣻 
{
	ElemType data;
	struct LNode *next;
};
typedef struct LqStack  //��ʽջ��
{
	struct LNode *base;
	struct LNode *top;
};
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
void CreateLq(LqStack &s)   //��ʽջ�Ĺ�����
{
	s.top = (LNode*)malloc(sizeof(LNode));
	s.top->next = NULL;
}
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
