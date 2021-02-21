#include <stdio.h>
#define MAX 10

int main() {
	printf("postfix increment\n");
	for (int i = 0; i < MAX; i++) {
		printf("%d\n", i);
	}

	printf("prefix increment\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d\n", i);
	}

}