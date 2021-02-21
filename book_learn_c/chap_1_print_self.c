#include <stdio.h>

int main()
{
	int c;
	char ch;
	
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}

	printf("dealing with while loop\n");

	while ((c = getchar()) != EOF) {
		printf("getchar()) != EOF = %d\n", getchar() != EOF);
		printf("inside loop: %c\n", c);
		putchar(c);
		putchar('\n');
	}
	return 0;
}