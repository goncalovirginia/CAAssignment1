#include <stdio.h>

/* Prints out the floats' sign and hidden bit */
void getSignAndBit(unsigned int bin) {
	if (bin == 0) {
		printf("+0.");
	}
	else if ((bin & 1 << 31) == 1 << 31) {
		printf("-1.");
	}
	else {
		printf("+1.");
	}
}

/* Prints out the floats' mantissa bits */
void getMantissa(unsigned int bin) {
	for (int i = 22; i >= 0; i--) {
		if ((bin & 1 << i) == 1 << i) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}

int main() {
	float num;
	
	scanf("%f", &num);
	unsigned int bin = *(unsigned int*) &num;
	
	getSignAndBit(bin);
	getMantissa(bin);
	
	return 0;
}
