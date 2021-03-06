/*
遍历二叉树*/
#include<stdio.h>
#include<malloc.h>
typedef struct Node{

	int data;

	struct Node* LChild;
	struct Node* RChild;
}Tree;
void createTree(Tree **T)
{
	int data = 1;
	scanf_s("%d", &data);
	if (data != 0)
	{


		*T = (Tree *)malloc(sizeof(Tree));
		(*T)->data = data;
		(*T)->LChild = NULL;
		(*T)->RChild = NULL;
		createTree(&(*T)->LChild);
		createTree(&(*T)->RChild);
	}
}
void printTree(Tree *T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		printTree(T->LChild);
		printTree(T->RChild);
	}

}
Tree * exchange_rootFirlst(Tree* T)   //先序遍历
{
	if (T != NULL)
	if (T->LChild != NULL || T->RChild != NULL)
	{
		Tree *p, *q;
		p = exchange_rootFirlst(T->LChild);
		q = exchange_rootFirlst(T->RChild);
		T->LChild = q;
		T->RChild = p;
	}
	return T;
}
void exchange_rootLast(Tree* T)    // 后序遍历
{
	if (T != NULL)
	if (T->LChild != NULL || T->RChild != NULL)
	{
		Tree *p, *q;
		q = T->RChild;
		p = T->LChild;
		T->LChild = q;
		T->RChild = p;
		exchange_rootLast(T->LChild);
		exchange_rootLast(T->RChild);

	}

}
Tree * exchange_rootMiddle(Tree* T)//类似于中序遍历，和中序遍历还有很大不同
{
	if (T != NULL)
	if (T->LChild != NULL || T->RChild != NULL)
	{
		Tree *p, *q;
		p = exchange_rootMiddle(T->LChild);

		q = T->RChild;
		T->RChild = p;
		T->LChild = q;
		q = exchange_rootMiddle(T->RChild);

	}

	return T;
}
//测试函数
void main()
{
	Tree *T;
	createTree(&T);
	printTree(T);
	printf("\n");
	exchange_rootFirlst(T);
	printTree(T);
	printf("\n");
	exchange_rootLast(T);
	printTree(T);
	printf("\n");
	exchange_rootMiddle(T);
	printTree(T);
	printf("\n");
}