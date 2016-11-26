#include "lmy.h"
#include "Stack.cpp"
#include "Queue.cpp"

void CreateLq(LqStack &s)   //链式栈的构建；
{
	s.top = (LNode*)malloc(sizeof(LNode));
	s.top->next = NULL;
}
void LqPush(LqStack &s)      //链式栈的入栈；
{
	LNode *p;
	cin >> s.top->data;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = s.top;  //....
	s.top = p;
}
ElemType LqGetTop(LqStack s)
//链式栈的出栈，返回一个ElemT类型；数，并释放此结点。
{
	LNode *p;
	ElemType e;
	p = s.top->next;
	e = p->data;
	s.top->next = p->next;
	free(p);
	return e;
}
void CreateSq(SqStack &s)        //顺序栈初始化;
{
	s.base = (ElemType *)malloc(MAX*sizeof(ElemType));
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
}
void Push(SqStack &s, ElemType e)   //顺序栈入栈;
{
	if ((s.top - s.base)>MAX || (s.top - s.base) == MAX)
		exit(OVERFLOW);
	*(s.top) = e;
	s.top++;
}
ElemType GetTop(SqStack &s)       //顺序栈出栈;
{
	ElemType e;
	if (s.top == s.base)//判断栈空;
		cout << "栈为空！" << endl;
	e = *(s.top - 1);
	s.top--;
	return e;
}