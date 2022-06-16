#include "monty.h"

/**
 * push - push unto a stack
 * @stack: the stack
 * @n: the item
 * Return: top of the stack
 */
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
	if (stack != NULL)
		stack->prev= s;
	s->n = n;
	return s;
}

/**
 * pop - pops off the stack
 * @stack: the stack
 * Return: top of the stack
 */
stack_t *pop(stack_t *stack)
{
	stack_t *next = stack->next;
	free(stack);
	if (next != NULL)
		next->prev = NULL;
	return stack->next;
}

/**
 * print_stack - prints a stack
 * @stack: the stack
 */
void print_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
