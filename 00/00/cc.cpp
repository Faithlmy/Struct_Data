#include<iostream>  
using namespace std;
#define ERROR 0  
#define OK 1  
#define STACK_ININ_SIZE 100  
#define STACKINCREMENT 10  
#define OVERFLOW -2  
typedef char TElemType;
typedef int Status;
typedef struct BiTNode
{//��������ṹ  
	TElemType data;
	struct BiTNode *lchild, *rchild;//���Һ���ָ��  
}BiTNode, *BiTree;
typedef struct Stack
{//��ջ�ṹ  
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &s)
{
	s.base = (BiTree*)malloc(STACK_ININ_SIZE *sizeof(BiTree));
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_ININ_SIZE;
	return OK;
}
Status EmptyStack(SqStack s)
{
	if (s.base == s.top)
		return OK;
	else
		return ERROR;
}
Status GetTop(Stack s, BiTree &e)
{

	if (s.top == s.base)
		return ERROR;
	e = *(s.top - 1);
	return OK;
}
Status Push(SqStack &s, BiTree &e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (BiTree *)realloc(s.base, (s.stacksize + STACKINCREMENT) *sizeof(BiTree));
		if (!s.base)
			exit(OVERFLOW);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
	return OK;
}
Status Pop(SqStack &s, BiTree &e)
{
	if (s.top == s.base)
		return ERROR;
	e = *--s.top;
	return OK;
}
Status CreatBiTree(BiTree &T)
{//�ݹ��㷨�����������  
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	return OK;
}
Status PreOrderTraverse1(BiTree T)
{//�ݹ��㷨�������������  
	if (!T)
		return ERROR;
	cout << T->data;
	PreOrderTraverse1(T->lchild);
	PreOrderTraverse1(T->rchild);
	return OK;
}
Status InOrderTraverse1(BiTree T)
{//�ݹ鷽���������������  
	if (T)
	{
		InOrderTraverse1(T->lchild);
		cout << T->data;
		InOrderTraverse1(T->rchild);
	}
	return OK;
}
Status PostOrderTraverse1(BiTree T)
{//�ݹ鷽���������������  
	if (T)
	{
		PostOrderTraverse1(T->lchild);
		PostOrderTraverse1(T->rchild);
		cout << T->data;
	}
	return OK;
}
Status PreOrderTraverse2(BiTree T)
{//�ǵݹ��㷨�����������  
	SqStack s;
	BiTree p;
	p = T;
	InitStack(s);
	Push(s, T);
	while (!(EmptyStack(s)))
	{
		while (GetTop(s, p) && p)
		{
			cout << p->data;
			p = p->lchild;
			Push(s, p);
		}
		Pop(s, p);
		if (!EmptyStack(s))
		{
			Pop(s, p);
			p = p->rchild;
			Push(s, p);
		}
	}
	return OK;
}
Status InOrderTraverse2(BiTree T)
{//�ǵݹ��㷨�����������  
	SqStack s;
	BiTree p;
	p = T;
	InitStack(s);
	Push(s, T);
	while (!EmptyStack(s))
	{
		while (GetTop(s, p) && p)
			Push(s, p->lchild);
		Pop(s, p);
		if (!EmptyStack(s))
		{
			Pop(s, p);
			cout << p->data;
			Push(s, p->rchild);
		}
	}
	return OK;
}
Status PostOrderTraverse2(BiTree T)
{
	BiTree p = T;
	SqStack s;
	InitStack(s);
	Push(s, T);
	BiTree Have_visited = NULL;
	while (!EmptyStack(s))
	{
		if (GetTop(s, p) && p->lchild&&Have_visited != p->lchild&&!(p->rchild&&Have_visited == p->rchild))
			Push(s, p->lchild);
		else if (p->rchild&&Have_visited != p->rchild)
			Push(s, p->rchild);
		else
		{
			Pop(s, p);
			cout << p->data;
			Have_visited = p;
		}
	}
	return OK;
}
void main()
{
	BiTree T;
	cout << "���������ַ���#Ϊ�գ���" << endl;
	CreatBiTree(T);
	cout << "1���ݹ鷽�� ���������ֵΪ��" << endl;
	PreOrderTraverse1(T);
	cout << endl;
	cout << "2���ǵݹ鷽�����������ֵΪ��" << endl;
	PreOrderTraverse2(T);
	cout << endl;
	cout << "3���ݹ鷽�� ���������ֵΪ��" << endl;
	InOrderTraverse1(T);
	cout << endl;
	cout << "4���ǵݹ鷽�����������ֵΪ��" << endl;
	InOrderTraverse2(T);
	cout << endl;
	cout << "5���ݹ鷽�� ���������ֵΪ��" << endl;
	PostOrderTraverse1(T);
	cout << endl;
	cout << "6���ǵݹ鷽�����������ֵΪ��" << endl;
	PostOrderTraverse2(T);
	cout << endl;
}