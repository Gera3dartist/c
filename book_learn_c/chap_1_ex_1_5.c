#include <stdio.h>
int main()
{
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;


	printf("fahr\t\tcelius\n");
	for (int fahr = upper; fahr >= lower; fahr = fahr - step) {
		celsius = (5.0/9.0) * (fahr-32.0);
		
		printf("%3.0f\t\t%6.2f\n", (double)fahr, celsius);
	}
	return 0;
}