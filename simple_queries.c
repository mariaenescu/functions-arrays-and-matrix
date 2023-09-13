//Enescu Maria, 311CA

#include <stdio.h>

int cmmdc(int x, int y)
{
	while (x != y) {
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	return x;
}

void ordoneaza(char rezultat[], int m[], int k)
{
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (max < m[i])
			max = m[i];
		rezultat[i] = 'a' + i;
	}
	if (max > 0) {
		int j = 0;
		while (j < k) {
			for (int i = 0; i < 26 && j < k; i++) {
				if (max == m[i]) {
					rezultat[j] = 'a' + i;
					j++;
				}
			}
			max--;
		}
	}
}

int main(void)
{
	int litere[26] = {0}, ultima_alerta = 0, nr_litere_citite = 0;
	char caracter, spatiu;
	while (1) {
		scanf("%c", &caracter);
		scanf("%c", &spatiu);
		if (caracter >= 'a' && caracter <= 'z') {
			litere[caracter - 'a']++;
			ultima_alerta++;
			nr_litere_citite++;
			if (ultima_alerta >= 5) {
				char vect_rezultat[26];
				ordoneaza(vect_rezultat, litere, 1);
				int n = litere[vect_rezultat[0] - 'a'];
				if (n >= (nr_litere_citite / 2.0)) {
					ultima_alerta = 0;
					int r = cmmdc(n, nr_litere_citite);
					printf("%c ", vect_rezultat[0]);
					printf("%d/%d\n", n / r, nr_litere_citite / r);
				}
			}
		} else if (caracter == 'Q') {
			scanf("%c", &caracter);
			scanf("%c", &spatiu);
			printf("%c %d\n", caracter, litere[caracter - 'a']);
		} else if (caracter == 'E') {
			scanf("%c", &caracter);
			scanf("%c", &spatiu);
			nr_litere_citite -= litere[caracter - 'a'];
			litere[caracter - 'a'] = 0;
		} else if (caracter == 'T') {
			int top = 0;
			do {
				scanf("%d", &top);
				scanf("%c", &spatiu);
			} while (top < 0 || top > 26);
			char vect_rezultat[26];
			ordoneaza(vect_rezultat, litere, top);
			for (int i = 0; i < top; i++) {
				if (i == top - 1)
					printf("%c", vect_rezultat[i]);
				else
					printf("%c ", vect_rezultat[i]);
			}
			printf("\n");
		} else {
			break;
		}
	}
	return 0;
}
