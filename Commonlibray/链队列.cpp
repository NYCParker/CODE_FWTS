#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE	10



typedef int QElemType;

/*节点结构*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

/*队列的链表结构*/
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;


int Push(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuepPtr)malloc(sizeof(QNode));
	if(!s)
	{
		return -1;	
	}
	
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	q->rear = s;
	return 0;
}

int Pull(LinkQueue *Q)
{
	QueuePtr s;
	if(Q->front == Q->rear)
		return -1;
	
	s = Q->front->next;
	Q->front->next = s->next;
	
	if(Q->rear == s)
		Q->rear = Q->front;
	free(s);
	
	return 0;
}

