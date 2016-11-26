#include "lmy.h"
#include "Stack.cpp"
#include "Queue.cpp"

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
void CreateSq(SqStack &s)        //˳��ջ��ʼ��;
{
	s.base = (ElemType *)malloc(MAX*sizeof(ElemType));
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
}
void Push(SqStack &s, ElemType e)   //˳��ջ��ջ;
{
	if ((s.top - s.base)>MAX || (s.top - s.base) == MAX)
		exit(OVERFLOW);
	*(s.top) = e;
	s.top++;
}
ElemType GetTop(SqStack &s)       //˳��ջ��ջ;
{
	ElemType e;
	if (s.top == s.base)//�ж�ջ��;
		cout << "ջΪ�գ�" << endl;
	e = *(s.top - 1);
	s.top--;
	return e;
}