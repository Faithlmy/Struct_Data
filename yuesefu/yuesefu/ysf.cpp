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
/*  n Ϊ������                                                          */
/*  k Ϊ��һ����ʼ��������                                              */
/*  mΪ�����ߺ�������                                                   */
/************************************************************************/
void Josephus(int n, int k, int m)
{
	//pnode Ϊ��ǰ�ڵ㣬secondnodeΪ�����ڵ㣬ָ��pnode��ǰ���ڵ㣬listΪͷ���  
	if (n<0 || k<0 || m<0) return;
	LinkList pnode, prenode, curr;
	pnode = new LNode();
	pnode->data = 1;
	pnode->link = pnode;            //����һ��ѭ������  
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
		prenode = pnode;        //prenode��pnode��ǰһ����㡣  
		pnode = pnode->link; //�ƶ���� pnode�ǵ�k��Ԫ��  
	}
	while (n--)
	{
		//for ���ƶ�m��λ��pnode���ƶ�����mλ�ã�prenode��pnode��ǰһ�����  
		for (int s = m; --s; prenode = pnode, pnode = pnode->link);
		prenode->link = pnode->link; //ɾ��pnode���  
		printf("%d   ", pnode->data); //��ӡɾ���Ľ��  
		free(pnode);                //�ͷſռ�  
		pnode = prenode->link;      //��prenode����һ����㿪ʼ����һ��m������ֵ��         
	}
}
void main()
{
	Josephus(5, 3, 1);
	system("pause");
}