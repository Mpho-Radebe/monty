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
		if (stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty", line_no);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%d\n", (*stack)->n);
		}
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instr);
		exit(EXIT_FAILURE);
	}
}