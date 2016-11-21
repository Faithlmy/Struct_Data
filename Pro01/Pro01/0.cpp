#include<iostream>
#include<queue>
#include<stack>
#include<stdlib.h>
#define MAX 100
using namespace std;

typedef struct
{
	int edges[MAX][MAX];    //�ڽӾ���
	int n;                  //������
	int e;                  //����
}MGraph;

bool visited[MAX];          //��Ƕ����Ƿ񱻷��ʹ�

void creatMGraph(MGraph &G)    //������������
{
	int i, j;
	int s, t;                 //�洢������
	int v;                   //�洢�ߵ�Ȩֵ
	for (i = 0; i<G.n; i++)       //��ʼ��
	{
		for (j = 0; j<G.n; j++)
		{
			G.edges[i][j] = 0;
		}
		visited[i] = false;
	}
	for (i = 0; i<G.e; i++)      //�Ծ������ڵı߸�Ȩֵ
	{
		scanf_s("%d %d %d", &s, &t, &v);   //����ߵĶ������Լ�Ȩֵ
		G.edges[s][t] = v;
	}
}

void DFS(MGraph G, int v)      //�����������
{
	int i;
	printf("%d ", v);          //���ʽ��v
	visited[v] = true;
	for (i = 0; i<G.n; i++)       //������v���ڵ�δ�����ʹ��Ľ��
	{
		if (G.edges[v][i] != 0 && visited[i] == false)
		{
			DFS(G, i);
		}
	}
}

void DFS1(MGraph G, int v)   //�ǵݹ�ʵ��
{
	stack<int> s;
	printf("%d ", v);        //���ʳ�ʼ���
	visited[v] = true;
	s.push(v);              //��ջ
	while (!s.empty())
	{
		int i, j;
		i = s.top();          //ȡջ������
		for (j = 0; j<G.n; j++)  //�����붥��i���ڵĶ���
		{
			if (G.edges[i][j] != 0 && visited[j] == false)
			{
				printf("%d ", j);     //����
				visited[j] = true;
				s.push(j);           //���������ջ
				break;               //�ҵ�һ������δ���ʵĶ��㣬����֮��������ѭ��
			}
		}
		if (j == G.n)                   //�����i���ڵĶ��㶼�����ʹ����򽫶���i��ջ
			s.pop();
	}
}

void BFS(MGraph G, int v)      //�����������
{
	queue<int> Q;             //STLģ���е�queue
	printf("%d ", v);
	visited[v] = true;
	Q.push(v);
	while (!Q.empty())
	{
		int i, j;
		i = Q.front();         //ȡ���׶���
		Q.pop();
		for (j = 0; j<G.n; j++)   //��ȱ���
		{
			if (G.edges[i][j] != 0 && visited[j] == false)
			{
				printf("%d ", j);
				visited[j] = true;
				Q.push(j);
			}
		}
	}
}

int main(void)
{
	int n, e;    //������ͼ�Ķ������ͱ���
	while (scanf_s("%d %d", &n, &e) == 2 && n>0)
	{
		MGraph G;
		G.n = n;
		G.e = e;
		creatMGraph(G);
		DFS(G, 0);
		printf("\n");
		//    DFS1(G,0);
		//    printf("\n");
		//    BFS(G,0);
		//    printf("\n");
	}
	return 0;
}