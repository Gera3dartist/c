#include <stdio.h>
#define MAX_LENGTH 100
#define LINE_START 1


int get_line(char line[], int maxlen);
void trim(char line[], int length);


int main() {

	char line[MAX_LENGTH];
	int length;
	
	while ((length = get_line(line, MAX_LENGTH)) > 0) {
		printf("length: %d\n", length);
		trim(line, length);
	}
	return 0;
}


void trim(char line[], int length) {
	int start, end;
	char trimmed[MAX_LENGTH];
	start = 0;
	end = length;

	while (start < MAX_LENGTH && (line[start] == ' ' || line[start] == '\t')) start++;
	while (end >= start && (line[end] == ' ' || line[end] == '\t' || line[end] == '\0'|| line[end] == '\n')) end--;

	printf("start: %d, end: %d\n", start, end);
	int j = 0;
	for (int i=start; i<=end; i++) {
		trimmed[j] = line[i];
		j++;
	}

	printf("final result: %s | FINAL SYMBOL\n", trimmed);


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





