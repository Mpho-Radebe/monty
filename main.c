#include "monty.h"

/**
 * main - the main function
 * @argc: count of the program's arguments
 * @argv: command line arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	stack_t *stack = NULL;
	char line[51];
	int endOfFile;
	int error_code;
	
 	int line_no = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");

	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		line[0] = '\0';
		read_next_line(monty_file, line, 50, &endOfFile);
		
		if (line[0] != '\0')
			error_code = execute_monty_instr(&stack, line, line_no);
		
		if (endOfFile || error_code != 0)
			break;
		line_no++;
	}

	while (stack != NULL)
		stack = pop(stack);
	fclose(monty_file);
	
	if (error_code != 0)
		exit(EXIT_FAILURE);
	
	return (EXIT_SUCCESS); 
}
