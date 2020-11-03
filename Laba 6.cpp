#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int n, m, i, j, k, T;
	int** mt;
	printf("Введите размеры матрицы n на m\n");
	scanf_s("%d %d", &n, &m);
	mt = (int**)calloc(n, sizeof(int));
	if (!mt)
		return 1;
	for (i = 0; i < n; i++) {
		*(mt + i) = (int*)calloc(m, sizeof(int));
		if (!*(mt + i)) {
			for (j = m - 1; j >= 0; j--)
				free(*(mt + j));
			free(mt);
			return 1;
		}
	}
	printf("Заполните матрицу\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("Введите [%d, %d] ", i, j);
			scanf_s("%i", &mt[i][j]);
		}
	for (i = 0; i < n; i++){
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%d ", mt[i][j]);
	}   // Заполнение и вывод матрицы окончен
	for (k = 0; k < m; k++) 
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++) {
				if (mt[i][k] >= 0 || mt[j][k] >= 0)
					continue;
				if (mt[i][k] > mt[j][k]) // Сравниваем элементы
				{
						T = mt[i][k];
						mt[i][k] = mt[j][k]; // Меняет значения элементов местами
						mt[j][k] = T;
				}
			}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%d ", mt[i][j]);
	}
}