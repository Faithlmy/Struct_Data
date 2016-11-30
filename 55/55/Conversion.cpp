#include "lmy.h"
#include "QueueOperat.cpp"
#include "StackOperat.cpp"
#include "Queue.cpp"
#include "Stack.cpp"

void conversion()
{
	SqStack s;
	CreateSq(s);
	cout << "请输入需转换进制元素：";
	ElemType e, n;
	cin >> e;
	cout << "请输入转换成多少进制的权：";
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