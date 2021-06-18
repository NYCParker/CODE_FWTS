#include <stdlib.h>
#include <stdio.h>

#define	FALSE	0
#define	TRUE	1


typedef	struct	NODE	{
	struct	NODE	*link;
	int		value;
} Node, *LinkList;

LinkList creat_linklist(int n)//创建一个长度为n的单链表
{
    LinkList New_node;//新节点名称
    LinkList Tail_node;//最后一个节点名称
    LinkList Head_node = NULL;//头节点
    int c;
 
    for (size_t i = 0; i < n; i++)
    {
        printf("Please enter the data of node %d: ",i+1);
        scanf("%d", &c);//读取要插入的字符
        fflush(stdin);//清空缓存
        New_node = (LinkList)malloc( sizeof(Node) );//为新节点申请一块空间
        New_node->value = c;
        New_node->link = NULL;//顺序插入的每个节点后面都没有元素
 
        if ( Head_node==NULL )		
        {
            Head_node = New_node;//如果插入的节点是第一个节点，就挂在头节点后面
        }else
        {
            Tail_node->link = New_node;//若插入的节点不是第一个节点，就挂在最后一个节点的后面
        }
        Tail_node = New_node;//插入新节点后，这个已经插入的最新节点就成为了最后一个节点
        Tail_node->link = NULL;
    }
    return Head_node;
}

int
sll_insert( Node **rootp, int new_value)
{
	Node *previous;
	Node *New;
	Node *current;
	
	current = *rootp;
	previous = NULL;
	
	while ( current!= NULL && current->value < new_value )
	{
		previous = current;
		current = current->link;
	}
	
	New = (Node *)malloc(sizeof(Node));
	if (New == NULL)
		return FALSE;
	New->value = new_value;
	
	New->link = current;
	if(previous == NULL)
		*rootp = New;
	else                            
		previous->link = New;
	return TRUE;
	
}

int main(void)
{
	LinkList root = creat_linklist(3);
	
	
	int ret = sll_insert( &root , 3);
	
	while ( root != NULL )
    {
        printf("%d" , root->value);
        root = root->link;
    }
	
	
}