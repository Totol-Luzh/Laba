#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, s0, s1, j, k;
	int  *ms;
	setlocale(LC_ALL, "RUS");
	printf("Введите размер сигнала ");
	scanf_s("%d", &n);
	ms = (int*)calloc(n*3, sizeof(int));
	if (!ms)
	{
		printf("Место под массив не выделено");
		return 1;
	}
	printf("Введите утроенный сигнал ");
	for (k = 0; k < n*3; k++)
		scanf_s("%d", &ms[k]);
	for (k = 0; k < n*3; k++)
		printf("%d", ms[k]);
	printf("\n");
	for (j = 0; j < n; j++) {
		s0 = 0;
		s1 = 0;
		for (i = 0; i < 3; i++) {
			if (ms[j * 3 + i] == 0)
				s0 = s0 + 1;
			else
				s1 = s1 + 1;
		}
		if (s0 > s1)
			printf("0");

		else
			printf("1");
	}
	return 0;
}