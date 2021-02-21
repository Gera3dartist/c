#include <stdio.h>

int main()
{	
	long nc;
	nc = 0;
	while(getchar() != EOF)
	{
		nc++;
	}
	printf("total count of characters: %ld\n", nc);
	return 0;
}