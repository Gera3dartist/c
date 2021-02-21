#include <stdio.h>
#define IN 1   //entering the word
#define OUT 0  //exiting the word

int main() 
{
	int ch, nw, nl, nc, state;
	state = OUT;
	nw = nl = nc = 0;
	while ((ch = getchar()) != EOF)
	{

		nc++;
		if (ch == '\n') 
			nl++;
		else if (ch == ' ' || ch == '\n' || ch == '\t') {
			state = OUT;
		}
		else if (state == OUT) {
			nw++;
			state = IN;
		}
	}
	printf("chars: %d, lines: %d, words: %d\n", nc, nl, nw);
}