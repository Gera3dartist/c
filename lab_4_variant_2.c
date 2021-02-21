#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 30

/*
ЗАВДАННЯ:
1. Ознайомитись з алгоритмами сортування масивів та способами їхньої реалізації.
2. У якості індивідуального завдання необхідно написати програмний код, що реалізує сортування масивів методом «бульбашка».
3. Звернення до елементів масиву реалізувати за допомогою вказівника на масив.
4. Роздрукувати (вивести на екран) початковий масив та масив після виконання сортування.

Вихідні дані по варіантах (див. Додаток 5).

РЕЗУЛЬТАТ РОБОТИ ПОТРІБНО:
1.	Роздрукувати (вивести на екран) початковий масив та масиви після виконання сортування.
2.	Програмний код розмістити на сайті Repl.it (посилання виключно через кнопку «+ Share»).
3.	Звіт до комп’ютерного практикуму додати в свій Клас.

variant 2:
Заданий масив B [1..30]. Відсортувати всі елементи з n-го по k-ий за
зростанням.
*/

struct IntPair {
	int n, k;
};
void bubble_sort(int *arr, int n, int k);
void populate_array(int *arr, int size);
void show_array(int *arr, int size);
struct IntPair generate_n_k(int size);

int main(){
	srand(time(NULL));
	int *int_arr = (int*) malloc(SIZE * sizeof(int));

	populate_array(int_arr, SIZE);
	printf("Initial array\n");
	show_array(int_arr, SIZE);

	struct IntPair indexes = generate_n_k(SIZE);
	printf("Generated indexes, n - %d, k - %d\n", indexes.n, indexes.k);
	bubble_sort(int_arr, indexes.n, indexes.k);
	printf("Sorted array, for n=%d, k=%d\n", indexes.n, indexes.k);
	show_array(int_arr, SIZE);
	return 0;
}

void populate_array(int *arr, int size) {
	for (int i = 0; i < size; i++){
		*(arr+i) = rand() % size;
	}
}

struct IntPair generate_n_k(int size){
	int n, k;

	n = rand() % size/2;  // take first index in first half of array
	k = n + (rand() % size-n);  // take secode index in range betwen n and size
	if (n > k) { 
		int temp = n;
		n = k;
		k = temp;
	}
	struct IntPair nk = {.n = n, .k = k};
	return nk;
}


void show_array(int *parr, int size) {
	for (int i = 0; i < size; i++){
		for 
		printf("%d.\t%d\n", i, *(parr+i));
	}
}

void bubble_sort(int *arr, int n, int k) {
	for (int i = n; i < k; i++) {
		int pass_sorted = 1;
		for (int j = n; j < k - 1; j++) {
			if (*(arr+j) > *(arr+j+1)) {
				int temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
				pass_sorted = 0;
			}
		}
		if (pass_sorted == 1) {
			break;
		}

	}

}


















