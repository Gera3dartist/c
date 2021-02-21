#include <stdio.h>
#define MAX_LENGTH 100
#define LINE_START 1


int get_line(char line[], int maxlen);
void reverse(char line[], int length);



int main() {

	char line[MAX_LENGTH];
	int length;
	
	while ((length = get_line(line, MAX_LENGTH)) > 0) {
		reverse(line, length);
	}
	return 0;
}


void reverse(char line[], int length) {
	printf("initial: %s\n", line);
	int i = 0;
	printf("reversed: ");
	while (i <= length){
		printf("%c", line[length-i]);
		i++;
	}
	printf("\n");

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





