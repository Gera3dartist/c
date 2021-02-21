#include <stdio.h>

float to_fahr(float);

int main()
{
	float fahr, celsius;
	int lower, upper, step;
	lower = -263;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("fahr\t\tcelius\n");
	printf("------------------");
	while(celsius <= upper) {
		fahr = to_fahr(celsius);
		
		printf("%3.2f\t\t%6.0f\n", fahr, celsius);
		celsius = celsius + step;
	}
	return 0;
}

float to_fahr(float celsius) {
	return 1.8 * celsius+32.0;

}