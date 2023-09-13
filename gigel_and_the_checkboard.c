//Enescu Maria, 311CA

#include <stdio.h>
#include <stdint.h>
#define N 1000

void citire_matrice(int m[N][N], int n, int vizitat[N][N])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vizitat[i][j] = 0;
			scanf("%d", &m[i][j]);
		}
	}
}

int main(void)
{
	int m[N][N];
	unsigned long d = 0;
	int vizitat[N][N];
	int n;
	scanf("%d", &n);
	citire_matrice(m, n, vizitat);
	int i = 0, j = 0;
	vizitat[0][0] = 1;
	while (1) {
		long v = m[i][j];
		d += (v > 0 ? 1 : -1) * v;
		if (v == 0)
			break;
		if ((i + j) % 2 == 0) {
			if (v < 0) {
				if (-v <= j)
					j += v;
				else
					j = n - (-v - j) % n;
			} else {
				if (v + j >= n)
					j = (v - n + j) % n;
				else
					j += v;
			}
		} else {
			if (v < 0) {
				if (-v <= i)
					i += v;
				else
					i = n - ((-v - i) % n);
			} else {
				if (v + i >= n)
					i = (v - n + i) % n;
				else
					i += v;
			}
		}
		if (vizitat[i][j] == 1)
			break;
		vizitat[i][j] = 1;
	}
	printf("%lu", d);
	printf("\n");
	if (j < 26) {
		printf("%d %c\n", n - i, 'A' + j);
	} else {
		if (j < 26 * 26) {
			printf("%d %c%c\n", n - i, 'A' + (j / 26 - 1), 'A' + j % 26);
		} else {
			int r = j % (26 * 26);
			char col1 = 'A' + j / (26 * 26) - 1;
			char col2 = 'A' + (r / 26) - 1;
			printf("%d %c%c%c", n - i, col1, col2, 'A' + r % 26);
			printf("\n");
		}
	}
	return 0;
}
