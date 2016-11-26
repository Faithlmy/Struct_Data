#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100       //ջ��ѭ�����е����ֵ��
#define OVERFLOW -1

using namespace std;

typedef int ElemType;
typedef int Status;
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
void InitQueue(SqQueue &Q)      //��ʽ���еĳ�ʼ��;
{
	Q.rear = (LNode*)malloc(sizeof(LNode));
	if (!Q.rear)exit(OVERFLOW);//�ж��Ƿ�ɹ����ٿռ�;
	Q.front = Q.rear;
	Q.front->next = NULL;
}
void EnQueue(SqQueue &Q)   //��ʽ���е����;
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)exit(OVERFLOW);
	cin >> p->data;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
ElemType PoQueue(SqQueue &Q)//��ʽ���еĳ���;
{
	LNode *p;
	ElemType e;
	if (Q.rear == Q.front)exit(OVERFLOW);
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return e;
}
void Create_Sq(SqQueueCir &q)
{
	q.base = (ElemType*)malloc(MAX * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.front = q.rear = 0;
}
void InitQueue_Sq(SqQueueCir &q)//���
{
	if ((q.rear + 1) % MAX == q.front)exit(OVERFLOW);
	cin >> q.base[q.rear];
	q.rear = (q.rear + 1) % MAX;
}
ElemType DeQueue_Sq(SqQueueCir &q)
{
	if (q.front == q.rear)exit(OVERFLOW);
	ElemType e = q.base[q.front];
	q.front = (q.front + 1) % MAX;
	return e;
}
void Menu()
{
	cout <<"�����ּ�ѡ����Ӧ����\n";
	cout << "<1> ������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ����:\n";
	cout << "<2> ����˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ����:\n";
	cout << "<3> ������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���\n";
	cout << "<4> ����˳��洢ʵ��ѭ�����еĳ�ʼ������ӡ����Ӳ���:\n";
	cout << "<5> ����ջʵ������ת������һ��ʮ������ת����d��������:\n";
	cout << "<6> ���ö��д�ӡ8��������ǣ���д���򣬸����������������Ļ��ʾ8���������:\n";
	printf("<0> �˳�:\n");
}
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
void Create(SqQueueCirl &q)
{
	q.base = (ElemType*)malloc(10 * sizeof(ElemType));
	if (!q.base)exit(OVERFLOW);
	q.base[0] = 0;
	q.base[1] = 1; //ѭ�����еĵ�һ��Ԫ�ش�Ϊ1;
	q.temp = q.rear = 2;//��ͷ�����ָ��ָ��ڶ���Ԫ�ص�λ��;
	q.front = 1;
}
void Init(SqQueueCirl &q)
{
	if ((q.rear + 1) % 10 == q.front)
	{
		cout << "������";
		exit(OVERFLOW);
	}
	q.base[q.rear] = q.base[(q.front + 9) % 10] + q.base[q.front];
	q.rear = (q.rear + 1) % 10;
}
ElemType DeQueue_Sq(SqQueueCirl &q)
{
	if (q.front == q.rear)exit(OVERFLOW);
	ElemType e = q.base[q.front];
	q.front = (q.front + 1) % 10;
	return e;
}
void PascalTriangle()
{
	SqQueueCirl q;
	Create(q);
	int i = 8, k = 14;
	while (i--)
	{
		while (k--)
			cout << " ";
		while (q.front != q.temp)
		{
			Init(q);
			cout << DeQueue_Sq(q) << "   ";
		}//�����һ�е�iʱ��������һ�е�Ԫ��;
		q.base[(q.temp + 9) % 10] = 0;
		cout << endl;
		q.base[q.rear] = 1;
		q.rear = (q.rear + 1) % 10;
		q.temp = q.rear;
		k = (i - 1) * 2;
	}
}
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
