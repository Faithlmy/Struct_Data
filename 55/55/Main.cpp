#include "lmy.h"
#include "Menu.cpp"
#include "Queue.cpp"
#include "Stack.cpp"
#include "YanghuiTri.cpp"
#include "Conversion.cpp"


int main()
{
	int m, e, n;
	while (1)
	{
		Menu();
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "请输入需入栈元素个数：";
			LqStack head;
			CreateLq(head);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				LqPush(head);
			cout << "入栈完成！" << endl;
			while (head.top->next != NULL)
			{
				cout << LqGetTop(head) << "  ";
			}
			cout << endl;
			cout << "出栈完成！" << endl;
			break;
		case 2:
			cout << "请输入需入栈元素个数：";
			SqStack s;
			CreateSq(s);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
			{
				cin >> e;
				Push(s, e);
			}
			cout << "入栈完成！" << endl;
			while (s.base != s.top)
			{
				cout << GetTop(s) << "  ";
			}
			cout << endl;
			cout << "出栈完成！" << endl;
			break;
		case 3:
			cout << "请输入需入队元素个数：";
			SqQueue Q;
			InitQueue(Q);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				EnQueue(Q);
			cout << "入队完成！" << endl;
			while (Q.front != Q.rear)
			{
				cout << PoQueue(Q) << "  ";
			}
			cout << endl;
			cout << "出队完成！" << endl;
			break;
		case 4:
			cout << "请输入需入队元素个数：";
			SqQueueCir h;
			Create_Sq(h);
			cin >> m;
			cout << "请依次输入" << m << "个数：" << endl;
			while (m--)
				InitQueue_Sq(h);
			cout << "入队完成！" << endl;
			while (h.front != h.rear)
			{
				cout << DeQueue_Sq(h) << "  ";
			}
			cout << endl;
			cout << "出队完成！" << endl;
			break;

		case 5:
			conversion();
			break;

		case 6:
			PascalTriangle();
			break;

		case 0:
			exit(OVERFLOW);
		default:
			cout << "输入错误，请重新输入：" << endl;
			break;
		}
	}
	return 0;
}
