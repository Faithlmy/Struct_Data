#include "lmy.h"
typedef struct Stack   //顺序栈；
{
	ElemType *base;
	ElemType *top;
}SqStack;
typedef struct LNode    //链式栈的结点； 
{
	ElemType data;
	struct LNode *next;
};
typedef struct LqStack  //链式栈；
{
	struct LNode *base;
	struct LNode *top;
};