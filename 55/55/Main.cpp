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
			cout << "����������ջԪ�ظ�����";
			LqStack head;
			CreateLq(head);
			cin >> m;
			cout << "����������" << m << "������" << endl;
			while (m--)
				LqPush(head);
			cout << "��ջ��ɣ�" << endl;
			while (head.top->next != NULL)
			{
				cout << LqGetTop(head) << "  ";
			}
			cout << endl;
			cout << "��ջ��ɣ�" << endl;
			break;
		case 2:
			cout << "����������ջԪ�ظ�����";
			SqStack s;
			CreateSq(s);
			cin >> m;
			cout << "����������" << m << "������" << endl;
			while (m--)
			{
				cin >> e;
				Push(s, e);
			}
			cout << "��ջ��ɣ�" << endl;
			while (s.base != s.top)
			{
				cout << GetTop(s) << "  ";
			}
			cout << endl;
			cout << "��ջ��ɣ�" << endl;
			break;
		case 3:
			cout << "�����������Ԫ�ظ�����";
			SqQueue Q;
			InitQueue(Q);
			cin >> m;
			cout << "����������" << m << "������" << endl;
			while (m--)
				EnQueue(Q);
			cout << "�����ɣ�" << endl;
			while (Q.front != Q.rear)
			{
				cout << PoQueue(Q) << "  ";
			}
			cout << endl;
			cout << "������ɣ�" << endl;
			break;
		case 4:
			cout << "�����������Ԫ�ظ�����";
			SqQueueCir h;
			Create_Sq(h);
			cin >> m;
			cout << "����������" << m << "������" << endl;
			while (m--)
				InitQueue_Sq(h);
			cout << "�����ɣ�" << endl;
			while (h.front != h.rear)
			{
				cout << DeQueue_Sq(h) << "  ";
			}
			cout << endl;
			cout << "������ɣ�" << endl;
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
			cout << "����������������룺" << endl;
			break;
		}
	}
	return 0;
}
