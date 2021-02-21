#include <stdio.h>
/* max word length from wiki is 45 for English,
 but for purpose of this exercise we take 20 */
#define MAX_LENGTH 256
#define IN 1
#define OUT 0

int main() 
{
	/* 

	Prints histogram of frequencys of occurences of characters

	*/

	int ch;
	int chars[MAX_LENGTH];
	for (int i = 0; i < MAX_LENGTH; i++) {
		chars[i] = 0;
	}

	while ((ch = getchar()) != EOF) {
			chars[ch]++;
	}
	printf("Freq\tChar\n");
	for (int i; i < MAX_LENGTH; i++) {
		if (chars[i] == 0)
			continue;
		printf("%d\t%c\n", chars[i], i);
	}
}