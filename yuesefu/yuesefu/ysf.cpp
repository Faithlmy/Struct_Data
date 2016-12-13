#include <iostream>  
using namespace std;
#define  ERROR 0  
typedef struct LNode
{
	int data;
	struct LNode *link;
	LNode()
	{
		data = 0;
		link = NULL;
	}
}LNode, *LinkList;

/************************************************************************/
/*  n 为总人数                                                          */
/*  k 为第一个开始报数的人                                              */
/*  m为出列者喊到的数                                                   */
/************************************************************************/
void Josephus(int n, int k, int m)
{
	//pnode 为当前节点，secondnode为辅助节点，指向pnode的前驱节点，list为头结点  
	if (n<0 || k<0 || m<0) return;
	LinkList pnode, prenode, curr;
	pnode = new LNode();
	pnode->data = 1;
	pnode->link = pnode;            //建立一个循环链表  
	curr = pnode;
	for (int i = 2; i <= n; i++)
	{
		LinkList  temp = new LNode();
		temp->data = i;
		temp->link = curr->link;
		curr->link = temp;
		curr = temp;
	}
	prenode = curr;
	while (k--)
	{
		prenode = pnode;        //prenode是pnode的前一个结点。  
		pnode = pnode->link; //移动结点 pnode是第k个元素  
	}
	while (n--)
	{
		//for 是移动m个位置pnode是移动到的m位置，prenode是pnode的前一个结点  
		for (int s = m; --s; prenode = pnode, pnode = pnode->link);
		prenode->link = pnode->link; //删除pnode结点  
		printf("%d   ", pnode->data); //打印删除的结点  
		free(pnode);                //释放空间  
		pnode = prenode->link;      //从prenode的下一个结点开始，数一个m个结点的值。         
	}
}
void main()
{
	Josephus(5, 3, 1);
	system("pause");
}