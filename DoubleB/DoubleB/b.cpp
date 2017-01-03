#include<stdlib.h> 
#include<stdio.h> 
#include<ctype.h> 
#include<time.h> 
int n;
// 对顺序表L作双向冒泡排序 
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
	puts("输入待排列数的个数");
	scanf_s("%d", &n);
	puts("1:手动输入\n2:自动生成");
	scanf_s("%d", &i);
	while (i != 1 && i != 2)
	{
		puts("输入有误,请重新输入!");
		scanf_s("%d", &i);
	}
	switch (i)
	{
	case 1:printf("输入%d个待排列数\n", n);
		for (i = 1; i <= n; i++)
			scanf_s("%d", &a[i]);
		puts("输入的数列为:");
		for (i = 1; i <= n; i++)
		{
			printf("= ", a[i]);
			if (!(i)) putchar('\n');
		}
		break;
	case 2:
		srand(time(NULL));
		puts("输入生成数大小上限");
		scanf_s("%d", &m);
		printf("自动生成%d个随机数:\n", n);
		for (i = 1; i <= n; i++)
		{

			a[i] = rand() % m + 1;
			printf("= ", a[i]);
			if (!(i))
				putchar('\n');
		}
		break;
	}
	puts("双向冒泡排序");
	puts("排序结果:");
	DblBbbSort(a);
	for (i = 1; i <= n; i++)
	{
		printf("= ", a[i]);
		if (!(i)) putchar('\n');
	}
	getchar();
	system("pause");
}