#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE	10

typedef int QElemType;

/*循环队列的顺序存储结构*/
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue,*NSqQueue;

int InitQueue (NSqQueue Q)
{
	Q->front = 0;
	Q->rear	 = 0;
	return 0;
}

int GetQueueLength(NSqQueue Q)
{
	return (Q->rear-Q->front+MAXSIZE) % MAXSIZE;
}

int IsQueueFull(NSqQueue Q)
{
	return (Q->rear+1) % MAXSIZE == Q->front;
}

int IsQueueEmpty(NSqQueue Q)
{
	return Q->rear == Q->front;
}

/*若队列未满，则输入元素e为Q新的队尾元素*/
int PushQueue(NSqQueue Q, QElemType e)
{
	if(IsQueueFull(Q))
	{
		cout<<"Queue is full!"<<endl;
		return -1;
	}
		
	
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1) % MAXSIZE;
	
	return 0;
}

/*若队列未空，则删除Q中队头元素*/
int PullQueue(NSqQueue Q)
{
	QElemType e;
	if(IsQueueEmpty(Q))
		return -1;
	
	e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	
	return e;
}

int main()
{
	NSqQueue Q;
	InitQueue (Q);
	for(int i = 1;i <= 10;i++)
	{
		PushQueue(Q,i);
	}
	cout<<GetQueueLength(Q)<<endl;
	while(!IsQueueEmpty(Q))
	{
		cout<<PullQueue(Q)<<' ';
	}
	cout<<endl;
	
}