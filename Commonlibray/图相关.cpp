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

/*建立无向图的邻接矩阵*/
void CreateMGraph( MGraph *G )
{
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
		scanf(&G->vexs[i]);
	
	for(i = 0; i < G->numVertexes;i++)
		for(j = 0;j < G->numEdges;j++)
			G->arc[i][j] = INF;
	
	for( k = 0; k < G->numEdges;k++)
	{
		scanf("%d,%d,%d,&i,&j,&w");
		G->arc[j][i] = G->arc[i][i] = w;
	}
}

/*邻接表：数组与链表相结合的存储方法称为邻接表*/
typedef char VertexType; 
typedef int EdgeType; 
typedef struct EdgeNode /* 边表结点 */ 
{ 
	int adjvex; /* 邻接点域，存储该顶点对应的下标 */ 
	EdgeType weight; /* 用于存储权值，对于非网图可以不需要 */ 
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */ 	
}EdgeNode; 

typedef struct VertexNode /* 顶点表结点 */ 
{ 
	VertexType data; /* 顶点域，存储顶点信息*/
	EdgeNode *firstedge; /*边表头指针 */ 
}VertexNode, AdjList[ MAXVEX]; 

typedef struct { 
	AdjList adjList; 
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}GraphAdjList;

/*建立图的邻接表*/
void CreateALGraph (GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
	{
			scanf(&G->adjList[i].data);
			G->adjList[i].firstedge = NULL;
	}
		
	for( k = 0; k < G->numEdges;k++)
	{
		scanf("%d,%d",&i,&j);
		
		/*头插法创建单链表*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}

int main()
{
	
}