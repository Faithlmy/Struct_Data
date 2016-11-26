#include <stdio.h>
#include <stdlib.h>
#define SUCCESS     1
#define FLASE         0
typedef struct node
{
	int iData;
	struct node *pNext;
}Node, *LinkList;
//��ʼ������
//��������Ϊָ��ṹ���ָ��
LinkList Init_LinkList(LinkList pHead)
{
	pHead = NULL;
	return pHead;
}
//����������
int Get_Length(LinkList pHead)
{
	int iLength = 0;
	Node* pFlag = NULL;
	pFlag = pHead;
	while (pFlag != NULL)
	{
		iLength++;
		pFlag = pFlag->pNext;
	}
	return iLength;
}
//������
//�ɹ����뷵������ͷָ�룬���ɹ���ʾ���󣬷���ͷָ��
//pHead�����ͷָ��
//iLocate��λ��
//iData������
LinkList Inset_LinkList(LinkList pHead, int iLocate, int iData)
{
	int  iCount = 0;
	Node* pNode = NULL;
	Node* pFlag = NULL;
	pNode = (Node*)malloc(sizeof(pNode));

	if (iLocate == 1)
	{
		pNode->iData = iData;
		pNode->pNext = pHead;
		pHead = pNode;
		return pHead;
	}
	else if (iLocate <= (Get_Length(pHead) + 1))
	{
		pFlag = pHead;
		for (iCount = 1; iCount<iLocate - 1; iCount++)
			pFlag = pFlag->pNext;
		pNode->iData = iData;

		pNode->pNext = pFlag->pNext;
		pFlag->pNext = pNode;
		printf("Insert Success\n");
		return pHead;
	}
	else
	{
		free(pNode);
		printf("Locate is Error.Insert Failre\n");
		return pHead;
	}
}
//��������ɾ�����
//iDataΪҪɾ���Ľ��
LinkList Delete_Data_LinkList(LinkList pHead, int iData)
{
	LinkList pFlag1, pFlag2;
	pFlag1 = pHead;
	pFlag2 = pHead;

	if (pHead == NULL)
	{
		printf("del a empty LinkList\n");
		return pHead;
	}
	if (pHead->iData == iData)
	{
		pHead = pFlag1->pNext;
		//        free(pFlag1);
		printf("Del Succuess\n");
		return pHead;
	}
	pFlag1 = pFlag1->pNext;
	while (pFlag1->pNext != NULL)
	{
		if (pFlag1->iData == iData)
		{
			pFlag2->pNext = pFlag1->pNext;
			//            free(pFlag1);
			printf("Del Success");
			return pHead;
		}
		else
		{
			pFlag1 = pFlag1->pNext;
			pFlag2 = pFlag2->pNext;
		}
	}
	printf("no such data\n");
	return pHead;

}
//����λ��ɾ�����
//iLocateΪ��Ҫɾ����λ��
LinkList Delete_Locate_LinkList(LinkList pHead, int iLocate)
{
	LinkList pFlag = pHead;
	int iCount;
	if (pFlag == NULL)
	{
		printf("the LinkList is empty\n");
		return pHead;
	}
	else if (iLocate == 1)
	{
		pHead = pHead->pNext;
		printf("test1\n");
		printf("del Success");
		//        free(pFlag);
		return pHead;
	}
	else if (iLocate <= Get_Length(pHead))
	{

		for (iCount = 1; iCount <= iLocate - 2; iCount++)
		{
			pFlag = pFlag->pNext;
		}

		pFlag->pNext = pFlag->pNext->pNext;
		//        free(pFlag->pNext);
		printf("Del Success");
		return pHead;
	}
	else
	{
		printf("Locate error\n");
		return pHead;
	}
}
//�������ݺ���
int Input_iData(void)
{
	int iData;
	printf("\nplease input data : ");
	scanf_s("%d", &iData);
	return iData;
}
//����λ�ú���
int Input_iLocate(void)
{
	int iLocate;
	printf("\nplease input Locate : ");
	scanf_s("%d", &iLocate);
	if (iLocate>0)
		return iLocate;
	else
	{
		printf("Locate Error.\n ");
		return FLASE;
	}
}
//��ӡ���н��
int Printf_Node(LinkList pHead)
{
	LinkList pNode;
	pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d\t", pNode->iData);
		pNode = pNode->pNext;
	}
	return SUCCESS;                    //�ɹ�����SUCCESS
}
void Run_LinkList(void)
{
	int iChoose;
	int bRun;
	bRun = 1;
	//LinkList temp;
	LinkList pHead = NULL;
	//    pHead = Init_LinkList(pHead);
	while (bRun)
	{
		printf("1.Input data into LinkList.\n");
		printf("2.Delete data form LinkList by locate.\n");
		printf("3.Delete data form LinkList by data.\n");
		printf("4.Printf all data form LinkList.\n");
		printf("5.Quit Program.\n\n");
		printf("Please choose your mind : ");
		scanf_s("%d", &iChoose);
		printf("\n");
		switch (iChoose)
		{
		case 1: pHead = Inset_LinkList(pHead, Input_iLocate(), Input_iData());
			break;
		case 2: pHead = Delete_Locate_LinkList(pHead, Input_iLocate());
			break;
		case 3: pHead = Delete_Data_LinkList(pHead, Input_iData());
			break;
		case 4: Printf_Node(pHead);
			break;
		case 5: bRun = 0;
			break;
		default:printf("Your choose maybe is error,please try again.\n");
			break;
		}
		printf("\n\n");
		getchar();
	}
}
int main(void)
{
	Run_LinkList();
	return 0;
}