
#include<iostream>  
#include<stack>  
#include<queue>  
using namespace std;

//���������  
typedef struct BiTNode{
	//����  
	char data;
//���Һ���ָ��  
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//���������д���������  
int CreateBiTree(BiTree &T){
	char data;
	//�������������������н���ֵ��һ���ַ�������#����ʾ����  
	scanf_s("%c", &data);
	if (data == '#'){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		//���ɸ����  
		T->data = data;
		//����������  
		CreateBiTree(T->lchild);
		//����������  
		CreateBiTree(T->rchild);
	}
	return 0;
}
//���  
void Visit(BiTree T){
	if (T->data != '#'){
		printf("%c ", T->data);
	}
}
//�������  
void PreOrder(BiTree T){
	if (T != NULL){
		//���ʸ��ڵ�  
		Visit(T);
		//�������ӽ��  
		PreOrder(T->lchild);
		//�������ӽ��  
		PreOrder(T->rchild);
	}
}
//�������    
void InOrder(BiTree T){
	if (T != NULL){
		//�������ӽ��    
		InOrder(T->lchild);
		//���ʸ��ڵ�    
		Visit(T);
		//�������ӽ��    
		InOrder(T->rchild);
	}
}
//�������  
void PostOrder(BiTree T){
	if (T != NULL){
		//�������ӽ��  
		PostOrder(T->lchild);
		//�������ӽ��  
		PostOrder(T->rchild);
		//���ʸ��ڵ�  
		Visit(T);
	}
}
/* �������(�ǵݹ�)
˼·������T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
*/
void PreOrder2(BiTree T){
	stack<BiTree> stack;
	//p�Ǳ���ָ��  
	BiTree p = T;
	//ջ���ջ���p����ʱѭ��  
	while (p || !stack.empty()){
		if (p != NULL){
			//����ջ��  
			stack.push(p);
			//���ʸ��ڵ�  
			printf("%c ", p->data);
			//����������  
			p = p->lchild;
		}
		else{
			//��ջ  
			p = stack.top();
			stack.pop();
			//����������  
			p = p->rchild;
		}
	}//while  
}
/* �������(�ǵݹ�)
˼·��T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ������������󣬷��ʸ����ٱ�����������
�Ƚ�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ������T->data�����������T����������
*/
void InOrder2(BiTree T){
	stack<BiTree> stack;
	//p�Ǳ���ָ��  
	BiTree p = T;
	//ջ���ջ���p����ʱѭ��  
	while (p || !stack.empty()){
		if (p != NULL){
			//����ջ��  
			stack.push(p);
			//����������  
			p = p->lchild;
		}
		else{
			//��ջ�����ʸ��ڵ�  
			p = stack.top();
			printf("%c ", p->data);
			stack.pop();
			//����������  
			p = p->rchild;
		}
	}//while  
}

//�������(�ǵݹ�)  
typedef struct BiTNodePost{
	BiTree biTree;
	char tag;
}BiTNodePost, *BiTreePost;

void PostOrder2(BiTree T){
	stack<BiTreePost> stack;
	//p�Ǳ���ָ��  
	BiTree p = T;
	BiTreePost BT;
	//ջ���ջ���p����ʱѭ��  
	while (p != NULL || !stack.empty()){
		//����������  
		while (p != NULL){
			BT = (BiTreePost)malloc(sizeof(BiTNodePost));
			BT->biTree = p;
			//���ʹ�������  
			BT->tag = 'L';
			stack.push(BT);
			p = p->lchild;
		}
		//��������������Ϸ��ʸ��ڵ�  
		while (!stack.empty() && (stack.top())->tag == 'R'){
			BT = stack.top();
			//��ջ  
			stack.pop();
			printf("%c ", BT->biTree->data);
		}
		//����������  
		if (!stack.empty()){
			BT = stack.top();
			//���ʹ�������  
			BT->tag = 'R';
			p = BT->biTree;
			p = p->rchild;
		}
	}//while  
}
//��α���  
void LevelOrder(BiTree T){
	BiTree p = T;
	//����  
	queue<BiTree> queue;
	//���ڵ����  
	queue.push(p);
	//���в���ѭ��  
	while (!queue.empty()){
		//��ͷԪ�س���  
		p = queue.front();
		//����pָ��Ľ��  
		printf("%c ", p->data);
		//�˳�����  
		queue.pop();
		//���������գ������������  
		if (p->lchild != NULL){
			queue.push(p->lchild);
		}
		//���������գ������������  
		if (p->rchild != NULL){
			queue.push(p->rchild);
		}
	}
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	printf_s("���������\n");
	PreOrder(T);
	printf_s("\n");
	
	printf("�������(�ǵݹ�)��\n");
	PreOrder2(T);
	printf_s("\n");

	printf_s("���������\n");
	InOrder(T);
	printf_s("\n");
	
	printf_s("�������(�ǵݹ�)��\n");
	InOrder2(T);
	printf_s("\n");
	
	printf_s("���������\n");
	PostOrder(T);
	printf_s("\n");
	
	printf_s("�������(�ǵݹ�)��\n");
	PostOrder2(T);
	printf_s("\n");
	
	printf_s("��α�����\n");
	LevelOrder(T);
	printf_s("\n");

	
	
	return 0;
	
}
