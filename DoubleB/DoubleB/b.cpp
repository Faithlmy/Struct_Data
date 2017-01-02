#include<stdlib.h> 
#include<stdio.h> 
#include<ctype.h> 
#include<time.h> 
int n;
// ��˳���L��˫��ð������ 
void DblPPSort(int L[], int low, int high) {
	int i, fini = 0;
	while (low < high)
	{
		fini = 1;
		for (i = low; i <= high; i++)
		if (L[i] > L[i + 1])
		{
			L[0] = L[i];
			L[i] = L[i + 1];
			L[i + 1] = L[0];
			fini = 0;
		}
		if (fini) break;
		high--;
		for (i = high; i >= low; i--)
		if (L[i] > L[i + 1])
		{
			L[0] = L[i];
			L[i] = L[i + 1];
			L[i + 1] = L[0];
			fini = 0;
		}
		if (fini) 
			break;
		low++;
	}
}
void DblBbbSort(int L[])
{
	DblPPSort(L, 1, n - 1);
}
void main()
{
	int i, m, a[1000];
	puts("������������ĸ���");
	scanf_s("%d", &n);
	puts("1:�ֶ�����\n2:�Զ�����");
	scanf_s("%d", &i);
	while (i != 1 && i != 2)
	{
		puts("��������,����������!");
		scanf_s("%d", &i);
	}
	switch (i)
	{
	case 1:printf("����%d����������\n", n);
		for (i = 1; i <= n; i++)
			scanf_s("%d", &a[i]);
		puts("���������Ϊ:");
		for (i = 1; i <= n; i++)
		{
			printf("= ", a[i]);
			if (!(i)) putchar('\n');
		}
		break;
	case 2:
		srand(time(NULL));
		puts("������������С����");
		scanf_s("%d", &m);
		printf("�Զ�����%d�������:\n", n);
		for (i = 1; i <= n; i++)
		{

			a[i] = rand() % m + 1;
			printf("= ", a[i]);
			if (!(i))
				putchar('\n');
		}
		break;
	}
	puts("˫��ð������");
	puts("������:");
	DblBbbSort(a);
	for (i = 1; i <= n; i++)
	{
		printf("= ", a[i]);
		if (!(i)) putchar('\n');
	}
	getchar();
	system("pause");
}