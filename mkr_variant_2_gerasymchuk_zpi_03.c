#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
# define X 0
# define Y 1
# define Z 2
# define DET -1
# define COUNT_OF_EQUATIONS 3
# define COUNT_OF_MEMBERS 3


float find_determinant(float **matrix);
float **prepare_matrix(float *free_members, float base[COUNT_OF_EQUATIONS][COUNT_OF_EQUATIONS], int column);
float **arr_creator(short rows, short columns);
void free_array(float **farr, short rows);
void show_preface();
char get_sign(float *number);
void do_check(float c1, float x, float c2, float y, float c3, float z, float answer);


int main(){

	float det_x, det_y, det_z, det, x, y, z;
  show_preface();
  float base[COUNT_OF_EQUATIONS][COUNT_OF_EQUATIONS] = {
    {2, -4,  9},
    {7, 3, -6},
    {7, 9, -9},
  };


	float free_members[COUNT_OF_EQUATIONS] = {28, -1, 5};

  // ------------ Формуємо проміжні матриці ------------
  float **det_base_matrix = prepare_matrix(free_members, base, DET);
  float **det_x_matrix = prepare_matrix(free_members, base, X);
  float **det_y_matrix = prepare_matrix(free_members, base, Y);
  float **det_z_matrix = prepare_matrix(free_members, base, Z);

  // ------------ Знаходимо визначники ------------
	det = find_determinant(det_base_matrix);
	det_x = find_determinant(det_x_matrix);
	det_y = find_determinant(det_y_matrix);
	det_z = find_determinant(det_z_matrix);

  // ------------ Перевірка на існування рішень ------------
	if (det == 0.0 && (det_x != 0.0 || det_y != 0.0 || det_z != 0.0)) {
		printf("Система рівнянь не має розв'язку\n");
    return 0;
	}
	x = det_x/det;
	y = det_y/det;
	z = det_z/det;


  // ------------ Виводимо рішення ------------
  printf("Значення визначника матриці: %.f\n", det);
  printf("Значення x: %.f\n", x);
	printf("Значення y: %.f\n", y);
	printf("Значення z: %.f\n", z);
	printf("\nПеревірка:\n");
	for (int i=0; i < COUNT_OF_EQUATIONS; i++){
			printf("%.f*%.f %c %.f*%.f %c %.f*%.f = %2.f", 
        fabsf(base[i][X]), x, 
        get_sign(&base[i][Y]), fabsf(base[i][Y]), y, 
        get_sign(&base[i][Z]), fabsf(base[i][Z]), z, 
        free_members[i]
      );
      
      do_check(base[i][X], x, base[i][Y], y, base[i][Z], z, free_members[i]);
	}
  
		
	// ------------ Вивільнюємо пам'ять, яку займають проміжні матриці ------------
  free_array(det_base_matrix, COUNT_OF_EQUATIONS);
  free_array(det_x_matrix, COUNT_OF_EQUATIONS);
  free_array(det_y_matrix, COUNT_OF_EQUATIONS);
  free_array(det_z_matrix, COUNT_OF_EQUATIONS);
	return 0;
}


char get_sign(float *number){
  return (*(number) > 0.0) ? '+' : '-';
}


float **arr_creator(short rows, short columns)
{
  float **pf;
  pf = malloc(rows * sizeof(float));
  for (int row = 0; row < rows; row++){
    pf[row] = (float *)malloc(columns * sizeof(float));
  }
  return pf;
}

float **prepare_matrix(float *free_members, float base[COUNT_OF_EQUATIONS][COUNT_OF_EQUATIONS], int column) {
  float **farr = arr_creator(COUNT_OF_EQUATIONS, COUNT_OF_MEMBERS);
  int base_counter = 0;
  for (int row = 0; row < COUNT_OF_EQUATIONS; row++){
    for (int col = 0; col < COUNT_OF_EQUATIONS; col++){
      if (col == column && col != DET) {
        // assign free member
        farr[row][col] = *(free_members + base_counter);
        base_counter++;
        continue;
      }
      *(*(farr + row) + col) = base[row][col];
  }}
  return farr;
}

void free_array(float **farr, short rows)
{
  for (int r = 0; r < rows; r++){
    free(farr[r]);
  }
  free(farr);
}


float find_determinant(float **matrix)
{
	
	return
    matrix[0][0] * matrix[1][1] * matrix[2][2] + 
    matrix[0][2] * matrix[1][0] * matrix[2][1] + 
    matrix[2][0] * matrix[1][2] * matrix[0][1] - 

		matrix[0][2] * matrix[1][1] * matrix[2][0] -
    matrix[0][0] * matrix[2][1] * matrix[1][2] -
		matrix[2][2] * matrix[0][1] * matrix[1][0];

}

void show_preface()
{
  // ------------ Preface ------------
  //Роздрукувати (вивести на екран) поточну дату, назву заходу (МКР-2), № варіанта, ПІБ, індекс академічної групи, систему рівнянь (свій варіант), значення визначника матриці та результат розрахунку з перевіркою!
	time_t t; 
  time(&t);
  printf("Поточна дата: -  %s\n", ctime(&t));
  printf("Назва роботи -  МКР-2\nВаріант: 2\nПІБ: Герасимчук А.Ф.\nГрупа: ЗПІ-03\n");
  printf("\nСистема рівнянь:\n");
  printf(" | 2x - 4y + 9z = 28\n");
  printf("<| 7x + 3y - 6z = -1\n");
  printf(" | 7x + 9y -9z = 5\n\n");
}

void do_check(float c1, float x, float c2, float y, float c3, float z, float answer) 
{

  float found = c1 * x + c2 * y + c3 * z;
  (found == answer) ? 
    printf("\t->\tПравильно: %.f == %.f\n", found, answer) 
    : 
    printf("\t->\tНе правильно: %.3f != %.3f\n", found, answer);
}


 
float find_determinant2(float **matrix) {
    double det = 1;
 
    for(int j = 0; j < COUNT_OF_EQUATIONS; ++j) {
        int i_max = j;
        for(int i = j; i < COUNT_OF_MEMBERS; ++i)
            if(*(*(matrix + i) + j) > *(*(matrix + i_max) + j))
                i_max = i;
 
        if(i_max != j) {
            for(int k = 0; k < COUNT_OF_EQUATIONS; ++k) {
                double tmp = *(*(matrix + i_max) + k);
                *(*(matrix + i_max) + k) = *(*(matrix + j) + k);
                *(*(matrix + j) + k)  = tmp;
            }
 
            det *= -1;
        }
 
        if(fabsf(*(*(matrix + j) + j)) < 1e-12) {
            puts("Singular matrix!");
            return NAN;
        }
 
        for(int i = j + 1; i < COUNT_OF_EQUATIONS; ++i) {
            double mult = -(*(*(matrix + i) + j)) / *(*(matrix + j) + j);
            for(int k = 0; k < COUNT_OF_EQUATIONS; ++k)
                *(*(matrix + i) + k) += mult * *(*(matrix + j) + k);
        }
    }
 
    for(int i = 0; i < COUNT_OF_EQUATIONS; ++i)
        det *= *(*(matrix + i) + i);
 
    return det;
}