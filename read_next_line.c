#include "monty.h"

/**
 * read_next_line - reads the next line in the given file
 * @fp: file pointer
 * @str: string
 * @max_length: the maximum length
 * @endOfFile: end of file
 */
void read_next_line(FILE *fp, char *str, int max_length, int* endOfFile)
{
	int count = 0;
	char c;
	int first_space = 1;
	int first_print = 1;

	*endOfFile = 0;
	
	while (1)
	{
		c = getc(fp);
		if (c == EOF)
		{
			*endOfFile = 1;
			break;
		}
		if (c == '\n')
			break;
		if (isalnum(c))
		{
			str[count++] = c;
			first_print = 0;
			first_space = 1;
		}
		else if (isspace(c) && !first_print && first_space)
		{
			str[count++] = ' ';
			first_space = 0;
		}
		
		if (count >= max_length)
		{
			while(1)
			{
				c = getc(fp);
				if (c == EOF)
				{
					*endOfFile = 1;
					break;
				}
				if (c == '\n')
					break;
			}
			break;
		}
	}
	
	str[count] = '\0';
}
