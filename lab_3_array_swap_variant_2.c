#include <stdio.h>
# define SIZE 4

/*
Assignment: invert elemenent in 2 dimensional array against additional diagonal
Variant 4; 

char expected[SIZE][SIZE] = {
	  0    1    2    3

0	{'q', 'm', 'h', 'd'},

1	{'p', 'l', 'g', 'c'},

2	{'o', 'k', 'f', 'b'},

3	{'n', 'i', 'e', 'a'}

};

*/


char charr[SIZE][SIZE] = {
	{'a', 'b', 'c', 'd'},

	{'e', 'f', 'g', 'h'},

	{'i', 'k', 'l', 'm'},

	{'n', 'o', 'p', 'q'}
};

char expected[SIZE][SIZE] = {
	{'q', 'm', 'h', 'd'},

	{'p', 'l', 'g', 'c'},

	{'o', 'k', 'f', 'b'},

	{'n', 'i', 'e', 'a'}
};

void flip(char arr[SIZE][SIZE], int n);
void print_array(char arr[SIZE][SIZE]);
void check_result(char result[SIZE][SIZE], char expected[SIZE][SIZE]);


int main(int argc, char const *argv[])

{
	
	print_array(charr);
	flip(charr, SIZE);
	printf("Priting result of flipping against diagonal: \n");
	print_array(charr);
	check_result(charr, expected);
	
}

void print_array(char arr[SIZE][SIZE]){
	for (int i=0; i < SIZE; i++) {
		printf("\t");
		for (int j=0; j < SIZE; j++){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void check_result(char result[SIZE][SIZE], char expected[SIZE][SIZE]){
	printf("Running check...");
	for (int i=0; i < SIZE; i++) {
		for (int j=0; j < SIZE; j++){
			if (result[i][j] != expected [i][j]) {
				printf(
					"Failed: result[%d][%d] != expected[%d][%d]: %c != %c\n", 
					i, j, i, j, result[i][j], expected [i][j]
				);
				return;

			}
		}
	}
	printf("Success!\n");
}

void flip(char arr[SIZE][SIZE], int n) {
	int temp, i, j;

	for (i=0; i<n; i++) {	
		for (j=0; j<n; j++) {
		 	if (n-1-j == i || n-1-i == j) {
		 		break;
		 	}

		 	temp = arr[i][j];
		 	arr[i][j] = arr[n-1-j][n-1-i];
		 	arr[n-1-j][n-1-i] = temp;


		 }
	}
 }

















