#include "monty.h"

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
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instr);
		exit(EXIT_FAILURE);
	}
}