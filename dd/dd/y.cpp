#include <cstdlib>  
#include <iostream>  
#include <stack>  
#include <queue>  

using namespace std;

//����������   
typedef char ElementType;

typedef struct BiTreeNode
{
	ElementType data;
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild;
}BiTreeNode, *BiTree;

//�ݹ�Ľ���һ�ö�����   
//����Ϊ����������������   
void createBiTree(BiTree &T)
{
	char data;
	data = getchar();
	if (data == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiTreeNode;
		T->data = data;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//�ݹ�����һ�ö�����  
void destroyBiTree(BiTree &T)
{
	if (T)
	{
		destroyBiTree(T->lchild);
		destroyBiTree(T->rchild);
		delete T;
		T = NULL;
	}
}

//�������Ĳ�α������õ��˶���   
void levelOrderTraverse(const BiTree& T)
{
	queue<BiTree> q;
	BiTree p = NULL;

	if (T)//�������ǿգ��������   
	{
		q.push(T);
	}
	while (!q.empty())//���зǿ�   
	{
		p = q.front();
		q.pop();
		cout << p->data << " ";
		if (p->lchild)//���Ӳ��գ������   
		{
			q.push(p->lchild);
		}
		if (p->rchild)//�Һ��Ӳ��գ������   
		{
			q.push(p->rchild);
		}
	}
}

//������������ǵݹ����   
void iterativePreOrderTraverse(const BiTree& T)
{
	stack<BiTree> s;
	BiTree p = T;

	while (p || !s.empty())//p�ǿգ���ջ�ǿ�  
	{
		if (p)
		{
			//�������㣬�������ջ������������   
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		else
		{
			//�������ջ������������   
			p = s.top();
			s.pop();
			p = p->rchild;//ת�Һ��ӽ��   
		}
	}
}

//������������ǵݹ����   
void iterativeInOrderTraverse(const BiTree& T)
{
	stack<BiTree> s;
	BiTree p = T;

	while (p || !s.empty())//p�ǿգ���ջ�ǿ�  
	{
		if (p)
		{
			//��ָ���ջ ������������   
			s.push(p);
			p = p->lchild;
		}
		else
		{
			//��ָ����ջ�����ʸ���㣬����������   
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}

//�������ĺ���ǵݹ����   
void iterativePostOrderTraverse(const BiTree& T)
{
	stack<pair<BiTree, bool> > s;
	BiTree p = T;

	while (p || !s.empty())
	{
		if (p)
		{
			s.push(make_pair(p, false));//false��ʾ�����p��������δ����   
			p = p->lchild;
		}
		else
		{
			if (s.top().second == false)//������������δ����   
			{
				s.top().second = true;//��־������Ϊ�ѷ���   
				p = s.top().first->rchild;//����������   
			}
			else//�������ѷ���   
			{
				cout << s.top().first->data << " ";  //��������ֵ   
				s.pop();//������ջ   
			}
		}
	}
}

//����ǵݹ��������һ���汾   
void anotherIterativePostOrderTraverse(const BiTree& T)
{
	stack<pair<BiTree, bool> > s;
	BiTree p = T;

	do
	{
		while (p)
		{
			s.push(make_pair(p, false));
			p = p->lchild;
		}

		while (!s.empty() && s.top().second == true)
		{
			cout << s.top().first->data << " ";
			s.pop();
		}

		if (!s.empty())
		{
			s.top().second = true;
			p = s.top().first->rchild;
		}
	} while (!s.empty());
}

int main(int argc, char *argv[])
{
	BiTree T = NULL;

	createBiTree(T);//���������� ������AB#D##CE###   
	// createBiTreeWithGenList(T);//������A(B(,D),C(E))#  

	cout << "levelOrder: ";
	levelOrderTraverse(T);
	cout << endl;

	cout << "preOrder: "; //�������   
	// preOrderTraverse(T);  
	iterativePreOrderTraverse(T);
	cout << endl;

	cout << "inOrder: ";//�������   
	//  inOrderTraverse(T);  
	iterativeInOrderTraverse(T);
	cout << endl;

	cout << "postOrder: ";//�������   
	// postOrderTraverse(T);  
	// iterativePostOrderTraverse(T);  
	anotherIterativePostOrderTraverse(T);
	cout << endl;

	destroyBiTree(T);//���ٶ��������ͷſռ�   

	system("PAUSE");
	return EXIT_SUCCESS;
}