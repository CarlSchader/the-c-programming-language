#include<stdio.h>

#define UPPER 500
#define LOWER -200
#define STEP 20

float cels_to_fahr(float cels) {
	return ((9.0 / 5.0) * cels) + 32.0;
}

int main() {
	float cels;

	printf("cels   fahr\n");
	for (cels = UPPER; cels >= LOWER; cels = cels - STEP) {
		printf("%4.0f %6.1f\n", cels, cels_to_fahr(cels));
	}
}
