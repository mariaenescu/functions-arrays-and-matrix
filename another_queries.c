//Enescu Maria, 311CA

#include <stdio.h>
#define NR 1000

void citire_matrice(int a[NR][NR], int M)
{
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++)
			scanf("%d", &a[i][j]);
	}
}

void initializare(int v[NR], int M, int val)
{
	for (int k = 1; k <= M; k++)
		v[k] = val;
}

void linie(int a[NR][NR], int M, int l, int rezultat[NR])
{
	initializare(rezultat, M, 1);
	for (int k = 1; k <= M; k++) {
		if (a[l][k] != 0)
			rezultat[a[l][k]] = 0;
	}
}

void coloana(int a[NR][NR], int M, int c, int rezultat[NR])
{
	initializare(rezultat, M, 1);
	for (int k = 1; k <= M; k++) {
		if (a[k][c] != 0)
			rezultat[a[k][c]] = 0;
	}
}

void zona(int a[NR][NR], int M, int N, int z, int rezultat[NR])
{
	initializare(rezultat, M, 1);
	int cat = z / N;
	int rest = z % N;
	int i = cat * N + 1;
	int j = (rest - 1) * N + 1;
	if (rest == 0) {
		j = M - N + 1;
		i -= N;
	}
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < N; l++) {
			int t = a[i + k][j + l];
			if (t != 0)
				rezultat[t] = 0;
		}
	}
}

void afiseaza(int v[NR], int M)
{
	for (int k = 1; k <= M; k++)
		printf("%d ", v[k]);
	printf("\n");
}

void celula(int a[NR][NR], int M, int N, int x, int y, int rezultat[NR])
{
	if (a[x][y] != 0) {
		initializare(rezultat, M, 0);
	} else {
		int l[NR], c[NR], v[NR];
		linie(a, M, x, l);
		coloana(a, M, y, c);
		int catX = x / N;
		int restX = x % N;
		if (restX == 0)
			catX--;
		int catY = y / N;
		int restY = y % N;
		if (restY == 0)
			catY--;
		int z = catX * N + catY + 1;
		zona(a, M, N, z, v);
		for (int i = 1; i <= M; i++)
			rezultat[i] = l[i] * c[i] * v[i];
	}
}

int celula_valida(int a[NR][NR], int M, int N, int x, int y)
{
	for (int k = 1; k <= M; k++) {
		if (k != y && a[x][k] == a[x][y])
			return 0;
	}
	for (int k = 1; k <= M; k++) {
		if (k != x && a[k][y] == a[x][y])
			return 0;
	}
	int catX = x / N;
	int restX = x % N;
	if (restX == 0)
		catX--;
	int catY = y / N;
	int restY = y % N;
	if (restY == 0)
		catY--;
	int z = catX * N + catY + 1;
	int cat = z / N;
	int rest = z % N;
	int i = cat * N + 1;
	int j = (rest - 1) * N + 1;
	if (rest == 0) {
		j = M - N + 1;
		i -= N;
	}
	for (int l = i; l < i + N; l++) {
		for (int k = j; k < j + N; k++) {
			if (l != x && k != y && a[l][k] == a[x][y])
				return 0;
		}
	}
	return 1;
}

void valideaza6(int a[NR][NR], int M, int N)
{
	int sepoate = 0;
	int invalid = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i][j] == 0) {
				sepoate = 1;
			} else {
				invalid = celula_valida(a, M, N, i, j);
				if (invalid == 0)
					break;
			}
		}
		if (invalid == 0)
			break;
	}
	if (invalid == 0)
		printf("1\n");
	else if (sepoate == 1)
		printf("0\n");
	else
		printf("2\n");
}

int main(void)
{
	int a[NR][NR];
	int D, N, reg;
	scanf("%d", &N);
	scanf("%d", &D);
	int M = N * N;
	citire_matrice(a, M);
	int v[NR];
	while (D > 0) {
		scanf("%d", &reg);
		if (reg == 1) {
			int c;
			scanf("%d", &c);
			linie(a, M, c, v);
			afiseaza(v, M);
		} else if (reg == 2) {
			int c;
			scanf("%d", &c);
			coloana(a, M, c, v);
			afiseaza(v, M);
		} else if (reg == 3) {
			int c;
			scanf("%d", &c);
			zona(a, M, N, c, v);
			afiseaza(v, M);
		} else if (reg == 4) {
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			celula(a, M, N, x, y, v);
			afiseaza(v, M);
		} else if (reg == 5) {
			int x, y, c;
			scanf("%d", &x);
			scanf("%d", &y);
			scanf("%d", &c);
			if (a[x][y] == 0)
				a[x][y] = c;
		} else if (reg == 6) {
			valideaza6(a, M, N);
		}
		D--;
	}
	return 0;
}
