#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define STACK_TYPE int
#define STACK_SIZE	100
#define FALSE		0

static	STACK_TYPE	stack[STACK_SIZE];
static	int			top_element = -1;
static	StackNode * stack;

typedef	struct	STACK_NODE
{
	STACK_TYPE	value;
	struct	STACK_NODE *next;
} StackNode;

void push(STACK_TYPE value);
void pop (void);

STACK_TYPE top(void);
int is_empty(void);
int is_full(void);

void create_statck(size_t size)
{
	
}

void destroy_statck( void )
{
	while(!is_empty())
		pop();
}

int main()
{
	
	
}

void push(STACK_TYPE value)
{
//	assert( !is_full() );
//	top_element += 1；
//	stack[ top_element ] = value;
	StackNode *head = (StackNode *)malloc(sizeof(StackNode));
	assert(head!=NULL);
	head->value = value;
	head->next = stack;
	stack = head;
	

}
void pop (void)
{
//	assert( !is_empty() );
//	return stack[ top_element-- ];
	assert( !is_empty() 
	StackNode *head = statck;
	stack = head->next;
	free(head);
	
}

STACK_TYPE top(void)
{
//	assert( !is_empty() );
//	return stack[ top_element ];
	assert( !is_empty() );
	return stack->value;

}

int is_empty(void)
{
	return stack == NULL;
}

int is_full(void)
{
		return FALSE;
}