#include <stdio.h>

int main() 
{
	int ch;
	int has_space = 0;

	while((ch = getchar()) != EOF)
	{
		if (ch == ' ') 
		{	
			has_space = 1;
			continue;
		}
		else if (has_space == 1) 
		{
			putchar(' ');
			putchar(ch);
			has_space = 0;
		}
		else 
		{
			putchar(ch);
		}

		}
}
