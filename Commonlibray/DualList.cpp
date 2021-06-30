#include <bits/stdc++.h>
using namespace std;

typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;

void insertline(line *head, int i, int e)
{
	line *list = head;
	line *q,*s;
	
	int j = 0;
	
	while(j< i-1)
	{
		++j;
		list = list->next;
	}
	q = list->next;
	
	s = (line*)malloc(sizeof(line));
	s->data = e;
	
	s->next  = q;
	s->prior = list;
	q->prior = s;
	list->next	 = s;
}

//尾插法
void creatline(line *head, int n)
{
	line *rail = head;
	line *temp;
	
	for(int i = 2; i <= n;i++)
	{
		temp = (line*)malloc(sizeof(line));

		temp->data  = i;
		
		temp->next = rail->next;
		rail->next->prior = temp;
		rail->next = temp;
		temp->prior = rail;
		rail = temp;
	}
	rail->next = head;
	head->prior = rail;
	
}

//打印链表
void printLinkListRear(line *head)
{
    line* p=head->prior;
    cout<<"Print DualList backward"<<endl;
    while(p->prior!=head->prior)
    {
        cout<<p->data<<' ';
        p=p->prior;
    }
    cout<<p->data<<endl;
}
//打印链表
void printLinkListNext(line *head)
{
    line *p=head;
    cout<<"Print DualList Forward"<<endl;
    while(p->next!=head)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<p->data<<endl;
}

//链表删除
int linkListDelete(line *head,int data)
{
	line *p = head;
	line *target;
	while(p->next!=head)
	{
		if(p->next->data == data)
		{
			target = p->next;
			p->next = target->next;
			target->next->prior = p;
			free(target);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

line* initline(void)
{
	line *head = (line *)malloc(sizeof(line));
	head->prior = head;
	head->next	= head;
	head->data	= 1;
	line *list = head;
	
	cout<<"DualList Create sucessfully"<<endl;

	return head;
}

int main()
{
	line* head = initline();
	
	creatline(head,10);
	insertline(head,5,20);
	printLinkListNext(head);
    printLinkListRear(head);
    
    if(linkListDelete(head, 6))
    {
    	printLinkListNext(head);
    	printLinkListRear(head);	
	}
	else
	{
		cout<<"data do not exist"<<endl;
	}
    
}

