#include <stdio.h>
#include<locale.h>
void vvod_matrix(int**& mt, int n, int m)
{
	int i, k;
	for (i = 0; i < n; i++)
		for (k = 0; k < m; k++)
		{
			printf("vvedite [%d, %d] ", i, k);
			scanf_s("%i", &mt[i][k]);
		}
}

int main()
{
	int i, k, j, Sj, Si, T, n, m;
	setlocale(LC_ALL, "Rus");
	printf("Введите размер матрицы ");
	scanf_s("%d", &n);
	m = n;
	int** ms = new int* [m];
	for (int i=0; i<m; i++) {
		ms[i] = new int[n];
	}
		vvod_matrix(ms, n, n);
		for(i=0; i<n-1; i++) // Цикл i
			for (j=i+1; j<n; j++) // Цикл j
			{
				Si=0;
				Sj=0;
				for (k=0; k<n; k++) // Цикл k
					{
						Si=Si+ms[i][k]; // Находим сумму строки i
						Sj=Sj+ms[j][k]; // Находим сумму строки j
					}
				if(Si>Sj) // Сравниваем суммы строк
				{
					for (k=0; k<n; k++)
					{
						T=ms[i][k];
						ms[i][k]=ms[j][k]; // Меняет значения строк местами
						ms[j][k]=T;
					}
				}
				
			}
		for (i = 0; i < n; i++)
		{
			for (k = 0; k < n; k++)
				printf("%d ", ms[i][k]); // Выводит массив на экран
			printf("\n");
		}
}