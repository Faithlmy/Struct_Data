#include<iostream>  
#define N 63  

using namespace std;

char str[] = "ab#d##c#e##";
int i = -1;

typedef struct node
{
	struct node *leftChild;
	struct node *rightChild;
	char data;
}BiTreeNode, *BiTree;

//生成一个结点  
BiTreeNode *createNode(int i)
{
	BiTreeNode * q = new BiTreeNode;
	q->leftChild = NULL;
	q->rightChild = NULL;
	q->data = i;

	return q;
}
BiTree createBiTree1()
{
	BiTreeNode *p[N] = { NULL };
	int i;
	for (i = 0; i < N; i++)
		p[i] = createNode(i + 1);

	// 把结点连接成树  
	for (i = 0; i < N / 2; i++)
	{
		p[i]->leftChild = p[i * 2 + 1];
		p[i]->rightChild = p[i * 2 + 2];
	}

	return p[0];
}

void createBiTree2(BiTree &T)
{
	i++;
	char c;
	if (str[i] && '#' == (c = str[i]))
		T = NULL;
	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree2(T->leftChild);
		createBiTree2(T->rightChild);
	}
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int getDepth(BiTree T)
{
	if (NULL == T)
		return 0;

	return 1 + max(getDepth(T->leftChild), getDepth(T->rightChild));
}

int getNodeAtLevel(BiTree T, int level)
{
	//下面的条件可以修正为：if(NULL == T)，但最好不要修改  
	if (NULL == T || level < 1 || level > getDepth(T))
		return 0;

	if (1 == level)
		return 1;

	return getNodeAtLevel(T->leftChild, level - 1) + getNodeAtLevel(T->rightChild, level - 1);
}
int main()
{
	BiTree T1;
	T1 = createBiTree1();

	int i;
	int depth1 = getDepth(T1);
	for (i = -1; i <= depth1 + 1; i++)
		cout << "层次" << i << ": " << getNodeAtLevel(T1, i) << endl;
	cout << "*********" << endl;

	BiTree T2;
	createBiTree2(T2);

	int j;
	int depth2 = getDepth(T2);
	for (j = -1; j <= depth2 + 1; j++)
		cout << "层次" << j << ": " << getNodeAtLevel(T2, j) << endl;
	cout << "*********" << endl;

	return 0;
}