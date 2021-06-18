#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


#define QUEUE_TYPE  int
#define FALSE		0

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