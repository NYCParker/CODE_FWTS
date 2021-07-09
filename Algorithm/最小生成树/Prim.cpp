#include <bits/stdc++.h>
using namespace std;

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX	100
#define INF	65535

typedef struct
{
	VertexType vexs[MAXVEX];//顶点表
	EdgeType   arc[MAXVEX][MAXVEX];//邻接矩阵 边表
	int numVertexes, numEdges;//顶点数 边数
}MGraph;




/*建立无向图的邻接矩阵
9 9
35
0 0 0
0 1 10
0 5 11
1 0 10
1 1 0
1 2 18
1 6 16
1 8 12
2 2 0
2 3 22
2 8 8
3 2 20
3 3 0
3 4 20
3 7 16
3 8 21
4 3 20
4 4 0
4 5 26
4 7 7
5 0 11
5 4 26
5 6 17
6 1 16
6 5 17
6 6 0
6 7 19
7 3 16
7 4 7
7 6 19
7 7 0
8 1 12
8 2 8
8 3 21
8 8 0

*/
void CreateMGraph( MGraph *G )
{
	int i,j,k,w,len;
	scanf("%d %d",&G->numVertexes,&G->numEdges);	
	for(i = 0; i < G->numVertexes;i++)
		for(j = 0;j < G->numEdges;j++)
			G->arc[i][j] = INF;
	
	scanf("%d",&len);
	for( k = 0; k < len;k++)
	{
		scanf("%d %d %d",&i,&j,&w);
		G->arc[i][j] = w;
	}

	
	for(i = 0; i < G->numVertexes;i++)
	{
		for(j = 0;j < G->numEdges;j++)
		{
			cout<<G->arc[i][j]<<' ';
		}
		cout<<endl;
	}
		
}

/*Prim算法最小生成树*/
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	lowcost[0] = 0;
	adjvex[0] = 0;
	
	for(i = 1; i<G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	
	for(i = 1; i<G.numVertexes; i++)
	{
		min = INF;
		
		j = 1;
		k = 0;
		while(j < G.numVertexes)
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout<<adjvex[k]<<','<<k<<endl;
		lowcost[k] = 0;
		
		for(j = 1; j<G.numVertexes; j++)
		{
			if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
	
}

int main()
{
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	CreateMGraph(G);
	MiniSpanTree_Prim(*G);
		
}