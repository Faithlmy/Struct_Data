#include "lmy.h"
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