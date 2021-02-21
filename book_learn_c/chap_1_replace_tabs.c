#include <stdio.h>

int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '/') {putchar('/');putchar('/');}
		else if (ch == '\t') {putchar('\\'); putchar('t');}
		else if (ch == '\b') {putchar('\\'); putchar('b');}
		else {putchar(ch);}

	}


}