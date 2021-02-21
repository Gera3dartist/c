#include <stdio.h>
#define ARRAY_SIZE 4
#define DIVISOR 0

// Lab work, variant: 2
// swap over horizontal

char input[ARRAY_SIZE][ARRAY_SIZE] = {
	{'u','v','w','x'},
	{'y','z','p','q'},
	{'r','s','t','j'},
	{'k','l','m','n'},

};


/*
char input[][] = {
	{'u','v','w','x'},
	{'y','z','p','q'},
// -------------------- horizontal	
	{'r','s','t','j'},
	{'k','l','m','n'},

};

char output[][] = {
	{'k','l','m','n'},
	{'r','s','t','j'},
// -------------------- horizontal	
	{'y','z','p','q'},
	{'u','v','w','x'},
};
	
}

*/

// ------- functions declaration -------
void swap(char a[ARRAY_SIZE][ARRAY_SIZE], int size);
void output_array(char a[ARRAY_SIZE][ARRAY_SIZE], int size);

int main() {
	printf("\nInput: \n");
	output_array(input, ARRAY_SIZE);
	swap(input, ARRAY_SIZE);

	printf("Result: \n");
	output_array(input, ARRAY_SIZE);
}

// ------- functions implementation -------
void output_array(char a[ARRAY_SIZE][ARRAY_SIZE], int size){
	for (int i=0; i < size; i++) {
		for (int j=0; j < size; j++){
			printf("\t%c ", a[i][j]);
		}
		printf("\n\n");
		
		
	}
}

void swap(char a[ARRAY_SIZE][ARRAY_SIZE], int size) {
	int temp;
	for (int i = 0; i < size/2; i++) {	
		for (int j = 0; j < size; j++) {
		 	temp = a[i][j];
		 	a[i][j] = a[size-1-i][j];
		 	a[size-1-i][j] = temp;
		 }
	}
 }















