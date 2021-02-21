#include <stdio.h>
#define MAX_LENGTH 20

/*
Write a program to fold long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column  of input 

Make sure you do something smart with very long lines
and if there are no blanks or tabs before the specified column


 e.g. there is line: 
 "some clever sentence and then another and something went wrrrrrrrrrrrrrrrrrrooooooooooooooongggggg"


Algorithm:

1. read the line
2. if line longer then MAX_LENGTH, move the whole word onto new line

*/
void _getline(void);
void flush_array(int end);
int line[MAX_LENGTH];

int main() {
	_getline();
	return 0;
}


void _getline(void) 
{
	extern int line[];
	int c, counter, last_space = 0, i, j, k, end;

	for (int i = 0; (c=getchar()) != EOF && c != '\n'; i++)
	{	
		// reached last column, and still no end,
		// find last space and trim till there
		// output
		// last space garanteed  not last index
		if (i == MAX_LENGTH && (c != ' ' || c != '\t')){
			printf("split in the middle\n");
			end = (last_space == 0) ? MAX_LENGTH : last_space;
			flush_array(end);
			last_space = 0;
			i = 0;
		} else if (i == MAX_LENGTH - 1 && (c == ' ' || c == '\t')) {
			flush_array(MAX_LENGTH);

		}
		if (c == ' ' || c == '\t') {
			last_space = i;
		}

		line[i] = c;
	}

}

void flush_array(int end) {
	extern int line[];
	for (int i = 0; i < end; i++) {
		putchar(line[i]);
		line[i] = 0;
	}
	putchar('\n');

}





















