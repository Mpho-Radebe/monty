#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: the number
 * Return: 0 or 1
 */
int is_number(char *str)
{
	char *ch_ptr = str;
	int is_digit;

	while (*ch_ptr != '\0')
	{
		is_digit = *ch_ptr >= '0' && *ch_ptr <= '9';
		if (*ch_ptr != '+' && *ch_ptr != '-' && !is_digit)
			return (0);
		ch_ptr++;
	}
	return (1);
}

/**
 * execute_monty_instr - executes a monty opcode
 * @stack: the stack
 * @line: a line
 * @line_no: the line number
 * Return: 1 or 0
 */
int execute_monty_instr(stack_t **stack, char *line, int line_no)
{
	char instr[8];
	char temp_str[20];
	int second;
	int temp;
	int sum;
	stack_t *temp_t;
	
	char *line1 = line;
	while (*line1 != '\0')
	{
		*line1 = tolower(*line1);
		line1++;
	}
	
	
	if (line[0] == '#')
		return 0;
	
	sscanf(line, "%s", instr);
	if (strcmp(instr, "push") == 0)
	{
		sscanf(line, "%s %s", instr, temp_str);
		if (!is_number(temp_str))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			return (1);
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
			return (1);
		}
		else
		{
			printf("%d\n", (*stack)->n);
		}
	}
	else if (strcmp(instr, "pop") == 0)
	{
		if (*stack == NULL){
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
			return (1);
		}
		else
			*stack = pop(*stack);
	}
	else if (strcmp(instr, "swap") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
			return (1);
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
			return (1);
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
	else if (strcmp(instr, "sub") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
			return (1);
		}
		else
		{
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum = (*stack)->n - sum;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "div") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
			return (1);
		}
		else
		{
			if ((*stack)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_no);
				return (1);
			}
			
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum = (*stack)->n / sum;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "mod") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
			return (1);
		}
		else
		{
			if ((*stack)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_no);
				return (1);
			}
			
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum = (*stack)->n % sum;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "mul") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
			return (1);
		}
		else
		{			
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum = (*stack)->n * sum;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "div") == 0)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
			return (1);
		}
		else
		{
			if ((*stack)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_no);
				return (1);
			}
			
			sum = (*stack)->n;
			*stack = pop(*stack);
			sum = (*stack)->n % sum;
			*stack = pop(*stack);
			*stack = push(*stack, sum);
		}
	}
	else if (strcmp(instr, "pchar") == 0)
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
			return (1);
		}
		else
		{
			if ((*stack)->n > 126 || (*stack)->n < 0)
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
				return (1);
			}
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else if (strcmp(instr, "pstr") == 0)
	{
		temp_t = *stack;
		while (temp_t != NULL && temp_t->n != 0 && temp_t->n >= 0 && temp_t->n <= 126)
		{
			putchar(temp_t->n);
			temp_t = temp_t->next;
		}
		putchar('\n');
	}
	else if (strcmp(instr, "rotl") == 0)
	{
		temp_t = *stack;
		if (temp_t != NULL && temp_t->next != NULL)
		{
			while (temp_t->next != NULL)
				temp_t = temp_t->next;
			temp_t->next = *stack;
			(*stack)->prev = temp_t;
			*stack = (*stack)->next;
			temp_t->next->next = NULL;
			(*stack)->prev = NULL;
		}
	}
	else if (strcmp(instr, "rotr") == 0)
	{
		temp_t = *stack;
		if (temp_t != NULL && temp_t->next != NULL)
		{
			while (temp_t->next != NULL)
				temp_t = temp_t->next;
			
			temp_t->prev->next = NULL;
			temp_t->prev = NULL;
			temp_t->next = *stack;
			(*stack)->prev = temp_t;			
			*stack = temp_t;
		}
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instr);
		return (1);
	}
	
	return (0);
}