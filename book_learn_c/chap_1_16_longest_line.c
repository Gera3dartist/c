#include <stdio.h>
#define MAX_LENGTH 1000


int get_line(char line[], int maxlen);
void copy(char from[], char to[]);


int main() {

	char line[MAX_LENGTH];
	char max_line[MAX_LENGTH];
	int state, len, max;
	max = 0;
	
	while ((len = get_line(line, MAX_LENGTH)) > 0) {
		printf("returnted length: %d\n", len);
		if (len > max) {
			max = len;
			copy(line, max_line);
		}
	}
	if (max > 0) 
		printf("longest line is: %s\n", line);
		printf("longest line is: %d\n", max);
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

void copy(char from[], char to[]) {
	int index;
	index = 0;
	while ((to[index] = from[index]) != '\0') {
		index++;
	}

}





