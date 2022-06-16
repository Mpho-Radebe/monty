#include "monty.h"

/**
 * execute_monty_instr - executes a monty opcode
 * @stack: the stack
 * @line: a line
 * @line_no: the line number
 */
void execute_monty_instr(stack_t **stack, char *line, int line_no)
{
	char instr[8];
	char temp_str[20];
	int second;
	int temp;
	int sum;
	
	char *line1 = line;
	while (*line1 != '\0')
	{
		*line1 = tolower(*line1);
		line1++;
	}
	
	sscanf(line, "%s", instr);
	if (strcmp(instr, "push") == 0)
	{
		sscanf(line, "%s %s", instr, temp_str);
		if (atoi(temp_str) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		
		*stack = push(*stack, atoi(temp_str));
	}
	else if (strcmp(instr, "pall") == 0)
	{
		print_stack(*stack);
	}
	else if (strcmp(instr, "pint") == 0) 
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%d\n", (*stack)->n);
		}
	}
	else if (strcmp(instr, "pop") == 0)
	{
		*stack = pop(*stack);
	}
	else if (strcmp(instr, "swap") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
			exit(EXIT_FAILURE);
		}
		else
		{
			second = (*stack)->next->n;
			temp = (*stack)->n;
			(*stack)->n = second;
			(*stack)->next->n = temp;
		}
	}
	else if (strcmp(instr, "add") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
			exit(EXIT_FAILURE);
		}
		else
		{
			sum = 0;
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum += (*stack)->n;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "nop") == 0)
	{
		
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instr);
		exit(EXIT_FAILURE);
	}
}