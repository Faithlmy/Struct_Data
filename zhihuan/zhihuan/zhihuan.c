#include <stdio.h>  

/* Ҫ��ʱ�临�Ӷ�ΪO(n) */
void Divide(int array[], int n)
{
	int i = 0, j = 0;
	int temp = 0;
	for (j = 0; j < n; j++)
	{
		if (array[j] <= 0)  //��С��0�����ݴ���array[i]���������,i��0��ʼ  
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++;
		}
	}
}
int main(void)
{
	int i = 0;
	int a[10] = { -5, 82, 76, -4, 27, 34, -26, 92, 0, 7 };
	Divide(a, 10);
	for (i = 0; i < 10; i++)
		printf_s("%4d", a[i]);
	printf_s("\n");
	system("pause");

	return 0;
}