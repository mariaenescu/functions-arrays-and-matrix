//Enescu Maria, 311CA

#include <stdio.h>
#include <math.h>

unsigned long long produs_scalar;
unsigned long long maxA, maxB;
unsigned long long prevA, prevB;
int firstA = 1, firstB = 1;
double snormA, snormB;
double normaA, normaB;

void citire(long n)
{
	unsigned long long a, b;
	for (long i = 0; i < n; i++) {
		scanf("%llo %llo", &a, &b);
		if (a > maxA) {
			if (maxA != 0 || i > 0)
				firstA = 0;
			prevA = maxA;
			maxA = a;
		} else {
			if (a > prevA && a < maxA) {
				prevA = a;
				firstA = 0;
			} else {
				if (a != maxA)
					firstA = 0;
			}
		}
		if (b > maxB) {
			if (maxB != 0 || i > 0)
				firstB = 0;
			prevB = maxB;
			maxB = b;
		} else {
			if (b > prevB && b < maxB) {
				prevB = b;
				firstB = 0;
			} else {
				if (b != maxB)
					firstB = 0;
			}
		}
		snormA += a * a;
		snormB += b * b;
		produs_scalar += a * b;
	}
	normaA = sqrt(snormA);
	normaB = sqrt(snormB);
}

int main(void)
{
	long n;
	scanf("%ld", &n);
	citire(n);
	printf("%llu\n", produs_scalar);
	if (n < 2) {
		printf("-1 -1\n");
	} else {
		if (firstA == 1)
			prevA = maxA;
		if (firstB == 1)
			prevB = maxB;
		if (prevA == maxA)
			printf("-1 ");
		else
			printf("%llu ", prevA);
		if (prevB == maxB)
			printf("-1\n");
		else
			printf("%llu\n", prevB);
	}
	printf("%.7f ", normaA);
	printf("%.7f\n", normaB);
	return 0;
}
