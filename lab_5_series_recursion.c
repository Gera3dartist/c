#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define CIRCLE 360


double factorial(int n);
float cos_approximator(float rad_angle, int precision);
float normalize_result(float radian, int precission);


int main() {
  short test;
	int x, precision, periods;
	float rad_x, rad_x2, expected_result, result;

	printf("Provide angle in degree to calculate cos for: \n");
  scanf("%d", &x);
	printf("value for x:  %d\n", x);
	printf("Provide amount of steps: (high values may take a while to compute): \n");
	scanf("%d", &precision);


	rad_x = (float)(x * (M_PI / 180.0));

  if (rad_x >= 2 * M_PI) {
    result = normalize_result(rad_x, precision);
  } else {
    result = cos_approximator(rad_x, precision);
  }
	
printf("Radian given: %.6f\n", rad_x);
	expected_result = cos(rad_x);
	printf("Exact       cos(%.8f) = %.8f\n", rad_x, expected_result);
	printf("Calculated: cos(%.8f) = %.8f\tprecision = %d\n", rad_x, result, precision);
  printf("Precission:\t%.23Lf", fabs)
}

float cos_approximator(float rad_angle, int precision) {
	float result, temp;

	for (int i = 0; i < precision; i++) {
		temp = pow(-1, i) * pow(rad_angle, (float)( 2 * i )) / factorial( 2 * i );
    printf("n = %d, temp: %.23f\n", i, temp);
		if (isnan(temp) || isinf(temp)) {
			break;
		}
		result += temp;
	}
	return result;
}


/*
	Naive factorial implementation, assuming only positive scenarios
*/
double factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n-1);
}

float normalize_result(float radian, int precision) {
	int sign, periods;
	float reminder, result;

	periods = (int)(radian/M_PI);
	reminder = fmodf(radian, M_PI);
  
  if (reminder == 0) {
    sign = 1;
  } else if (periods % 2 != 0){
		sign = (reminder >= M_PI/2) ? 1 : -1;
	} else {
		sign = (reminder >= M_PI/2) ? -1 : 1;
	}
  printf("periods: %d\treminder: %.23f\n", periods, reminder);
	result = cos_approximator(reminder, precision);

	if ((result < 0 && sign == 1) || (result > 0 && sign == -1)) {
		result = (-1) * result;
	}

	return result;
}

