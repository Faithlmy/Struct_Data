#include "lmy.h"
#include "QueueOperat.cpp"
#include "StackOperat.cpp"
#include "Queue.cpp"
#include "Stack.cpp"

void conversion()
{
	SqStack s;
	CreateSq(s);
	cout << "��������ת������Ԫ�أ�";
	ElemType e, n;
	cin >> e;
	cout << "������ת���ɶ��ٽ��Ƶ�Ȩ��";
	cin >> n;
	while (e)
	{
		Push(s, e%n);
		e = e / n;
	}
	while (s.base != s.top)
	{
		cout << GetTop(s);
	}
	cout << "(" << n << ")";
	cout << endl;
}