#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

void revers(char* str, int i1, int i2)
{
	char c;
	while (i1 < i2)
	{
		c = *(str + i1);
		*(str + i1) = *(str + i2);
		*(str + i2) = c;
		i1++; i2--;
	}
}

char str[1000];
int main() {
	setlocale(LC_ALL, "Rus");
	int i, n1, n2, k1, k2, i1, i2, p1, p2;
	printf("Введите предложение\n");
	gets_s(str);
	system("CLS");
	printf(" Исходная строка\n ");
	printf("%s", str);
	i = 0;
	n1 = n2 = k1 = k2 = 0;
	while (*(str + i) != '\0') {
		while (*(str + i++) == ' ');
		i1 = i - 1;
		while (*(str + i) != ' ' && *(str + i) != '\0')
		i++;
		i2 = i - 1;
		if (!k1 && !k2) {
			n1 = n2 = i1;
			k1 = k2 = i2;
		}
		else {
			if (k1 - n1 < i2 - i1) {
				n1 = i1;
				k1 = i2;
			}
			else
				if (k2 - n2 > i2 - i1) {
					n2 = i1;
					k2 = i2;
				}
		}
	}
	revers(str, n1, k2);
	revers(str, n1, n1 + (k2 - n2));
	revers(str, k2 - (k1 - n1), k2);
	revers(str, n1 + (k2 - n2), k2 - (k1 - n1));
	printf("\n Преобразованная строка: %s\n", str);
	free(str);
	return 0;
}