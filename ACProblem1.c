#include <stdio.h>
#include <limits.h>

#define OVERFLOW "operation overflow\n"

/* Checks if the sum of 2 numbers will overflow */
int sumOverflow(long long num1, long long num2) {
	if (num1 > 0 && num2 > LLONG_MAX - num1 || num1 < 0 && num2 < LLONG_MIN - num1) {
		return 1;
	}
	return 0;
}

/* Checks if the product of 2 numbers will overflow */
int productOverflow(long long num1, long long num2) {
	long long product = num1 * num2;
	if (num1 != product/num2) {
		return 1;
	}
	return 0;
}

int main() {
	long long num1, num2;
	scanf("%lld %lld", &num1, &num2);
	
	if (sumOverflow(num1, num2)) {
		printf(OVERFLOW);
	}
	else {
		printf("%lld\n", num1 + num2);
	}
	
	if (productOverflow(num1, num2)) {
		printf(OVERFLOW);
	}
	else {
		printf("%lld\n", num1 * num2);
	}
	
	return 0;
}
