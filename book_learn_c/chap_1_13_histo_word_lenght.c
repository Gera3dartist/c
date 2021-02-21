#include <stdio.h>
/* max word length from wiki is 45 for English,
 but for purpose of this exercise we take 20 */
#define MAX_LENGTH 20
#define IN 1
#define OUT 0

int main() 
{
	/* 

	Prints histogram of lengths of words

	*/

	int ch, word_length, state;
	int lengths[MAX_LENGTH]; //represents array of lengths from 0 to 20;
	for (int i = 0; i < MAX_LENGTH; i++) {
		lengths[i] = 0;
	}
	state = OUT;
	word_length = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n')
			if (word_length > 0) {
				lengths[word_length]++;
				word_length = 0;
			} 
			else {
				continue;
			}

		else {
			word_length++;
		}
	}
	printf("Freq\tlength\n");
	for (int i; i < MAX_LENGTH; i++) {
		if (lengths[i] == 0)
			continue;
		printf("%d\t%d\n", lengths[i], i);
	}
}