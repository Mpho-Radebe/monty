#include "monty.h"

stack_t *push(stack_t *stack, int n)
{
	stack_t *s = (stack_t *)malloc(sizeof(stack_t));
	if (s == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	s->prev = NULL;
	s->next = stack;
	s->n = n;
	return s;
}

stack_t *pop(stack_t *stack)
{
	stack_t *top = stack;
	free(top);
	return stack->next;
}

void print_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
