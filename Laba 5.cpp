#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int ms[4][4], i, k, si, str, min;
	printf("Заполните массив 4*4\n");
	for (i = 0; i < 4; i++)
		for (k = 0; k < 4; k++) {
			printf("Введите [%d, %d] ", i, k);
			scanf_s("%d", &ms[i][k]);
		}
	printf("\n");
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) 
			printf("%d ", ms[i][k]);
		printf("\n");
	}
	printf("\n");
	min = 1000;
	str = 1;
	for (i = 0; i < 4; i++) {
			si = 0;
			for (k = 0; k < 4; k++)
				si = si + ms[i][k];
			printf("Сумма %d-ой строки = %d \n", i + 1, si);
			if (min > si) {
				min = si;
				str = i;
			}
	}
	printf("\n");
	for (k = 0; k < 4; k++)
		printf("%d " , ms[str][k]);
	return 0;
}
