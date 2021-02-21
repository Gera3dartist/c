#include <stdio.h>
#define MAX_LENGTH 1000
#define LONG_LINE 80


int get_line(char line[], int maxlen);


int main() {

	char line[MAX_LENGTH];
	char max_line[MAX_LENGTH];
	int state, len, max;
	max = 0;
	
	while ((len = get_line(line, MAX_LENGTH)) > 0) {
		if (len > LONG_LINE) {
			printf("longest line is: %s\n", line);
		}
	}
	return 0;
}

int get_line(char line[], int lim) {
	int ch, length;
	for(length = 0; ((ch = getchar()) != EOF && ch != '\n'); ++length) {

		if (length < lim - 2) {
			line[length] = ch;
		}
	}
	if (ch == '\n') {
		line[lim - 2] = '\n';
		length++;
	}


	line[lim - 1] = '\0';
	return length;
}





