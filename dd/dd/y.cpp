#include <cstdlib>  
#include <iostream>  
#include <stack>  
#include <queue>  

using namespace std;

//二叉树定义   
typedef char ElementType;

typedef struct BiTreeNode
{
	ElementType data;
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild;
}BiTreeNode, *BiTree;

//递归的建立一棵二叉树   
//输入为二叉树的先序序列   
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

//递归销毁一棵二叉树  
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

//二叉树的层次遍历，用到了队列   
void levelOrderTraverse(const BiTree& T)
{
	queue<BiTree> q;
	BiTree p = NULL;

	if (T)//若根结点非空，则入队列   
	{
		q.push(T);
	}
	while (!q.empty())//队列非空   
	{
		p = q.front();
		q.pop();
		cout << p->data << " ";
		if (p->lchild)//左孩子不空，入队列   
		{
			q.push(p->lchild);
		}
		if (p->rchild)//右孩子不空，入队列   
		{
			q.push(p->rchild);
		}
	}
}

//二叉树的先序非递归遍历   
void iterativePreOrderTraverse(const BiTree& T)
{
	stack<BiTree> s;
	BiTree p = T;

	while (p || !s.empty())//p非空，或栈非空  
	{
		if (p)
		{
			//输出根结点，根结点入栈，遍历左子树   
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		else
		{
			//根结点退栈，遍历右子树   
			p = s.top();
			s.pop();
			p = p->rchild;//转右孩子结点   
		}
	}
}

//二叉树的中序非递归遍历   
void iterativeInOrderTraverse(const BiTree& T)
{
	stack<BiTree> s;
	BiTree p = T;

	while (p || !s.empty())//p非空，或栈非空  
	{
		if (p)
		{
			//根指针进栈 ，遍历左子树   
			s.push(p);
			p = p->lchild;
		}
		else
		{
			//根指针退栈，访问根结点，遍历右子树   
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}

//二叉树的后序非递归遍历   
void iterativePostOrderTraverse(const BiTree& T)
{
	stack<pair<BiTree, bool> > s;
	BiTree p = T;

	while (p || !s.empty())
	{
		if (p)
		{
			s.push(make_pair(p, false));//false表示根结点p的右子树未访问   
			p = p->lchild;
		}
		else
		{
			if (s.top().second == false)//根结点的右子树未访问   
			{
				s.top().second = true;//标志右子树为已访问   
				p = s.top().first->rchild;//遍历右子树   
			}
			else//右子树已访问   
			{
				cout << s.top().first->data << " ";  //输出根结点值   
				s.pop();//根结点出栈   
			}
		}
	}
}

//后序非递归遍历的另一个版本   
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

	createBiTree(T);//建立二叉树 如输入AB#D##CE###   
	// createBiTreeWithGenList(T);//如输入A(B(,D),C(E))#  

	cout << "levelOrder: ";
	levelOrderTraverse(T);
	cout << endl;

	cout << "preOrder: "; //先序遍历   
	// preOrderTraverse(T);  
	iterativePreOrderTraverse(T);
	cout << endl;

	cout << "inOrder: ";//中序遍历   
	//  inOrderTraverse(T);  
	iterativeInOrderTraverse(T);
	cout << endl;

	cout << "postOrder: ";//后序遍历   
	// postOrderTraverse(T);  
	// iterativePostOrderTraverse(T);  
	anotherIterativePostOrderTraverse(T);
	cout << endl;

	destroyBiTree(T);//销毁二叉树，释放空间   

	system("PAUSE");
	return EXIT_SUCCESS;
}