#include <stdio.h>
#include<locale.h>
void funkc(int n, int &kl)
{
	kl = 0;
	while (n != 1){
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;
		kl = kl + 1; // Находится количество действий
	}
}

int main()
{
	int n, k, m, kl, x, j;
	setlocale(LC_ALL, "Rus");
	printf("Введите натуральное число >1\n");
	x=scanf_s("%d", &n); // Ввод значения
	if (n < 2 || x!=1) // Проверка на правельность введения данных
	{
		printf("\nДанные введены неверно\n");
		fflush(stdin);
		return -1;
	}
	funkc(n, kl); // Расчёт количества действий
	printf("n достигло 1 после %d таких повторений\n", kl);
	printf("Введите значения k и m, 1<k<n\n");
	x = scanf_s("%d, %d", &k, &m); // Ввод значений k и m
	if (x != 2 || k < 2 || k >= n) // Проверка на правельность введения данных
	{
		printf("\nДанные введены неверно\n");
		fflush(stdin);
		return -1;
	}
	for (j = k; j<n; j++) {  // Проверяем, что для значений от k до n процесс завершается не позднее, чем после m таких повторений
		funkc(j, kl); // Расчёт количества действий
		if (kl > m) 
			printf("Для значения %d условие не верно\n", j);
	}
	return 0;
}