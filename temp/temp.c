#include<stdio.h>

int main() {
	float fahr, cels;
	int lower, upper, step;

	lower = 0;
	upper = 200;
	step = 20;

	fahr = lower;

	printf("cels   fahr\n");
	
	while (cels <= upper) {
		fahr = ((9.0 / 5.0) * cels) - 32.0;
		printf("%4.0f %6.1f\n", cels, fahr);
		cels = cels + step;
	}
}
