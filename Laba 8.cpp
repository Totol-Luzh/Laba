#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Rus");
    char** str;
    char str2[15];
    int** numbers;
    int n, m, i, j, x, k, l, maxl;
    printf("Введите количество и длину строк: ");
    x = scanf_s("%d %d", &n, &m);
    if (x != 2) {
        printf("Данные введены не верно ");
        return 1;
    }
    str = (char**)calloc(n, sizeof(char*));
    if (!str) {
        printf("Место под массив не выделено");
        return 1;
    }
    for (i = 0; i < n; i++) {
        str[i] = (char*)calloc(m, sizeof(char));
        if (!str[i]) {
            for (j = m - 1; j >= 0; j--)
                free(str[j]);
            free(str);
            return 1;
        }
    } // Созданние массива строк завершено
    l = m / 2;
    numbers = (int**)calloc(n, sizeof(int));
    if (!numbers)
        return 1;
    for (i = 0; i < n; i++) {
        *(numbers+i) = (int*)calloc(m, sizeof(int));
        if (!numbers[i]) {
            for (j = m - 1; j >= 0; j--)
                free(numbers[j]);
            free(numbers);
            return 1;
        }
    } // Создание массива целых чисел завершено
    printf("Введите предложение\n");
    for (i = 0; i < n; i++) {
        rewind(stdin);
        gets_s(str[i], m);
    }
    printf("Заполните строки изображениями чисел через пробел\n");
    for (i = 0; i < n; i++) {
        printf("Строка %d:\n %s", i, str[i]);
        printf("\n");
    } // Заполнение строк завершено
    maxl = 0;
    for (i = 0; i < n; i++) { // Преобразование символов чисел в числа 
        k = 0;
        l = 0;
        while (str[i][k] != '\0') {
            j = 0;
            while (str[i][k] == ' ')
                k++;
            while (str[i][k] != ' ' && str[i][k] != '\0') {
                str2[j] = str[i][k];
                k++; j++;
            }
            str2[j] = '\0';
            numbers[i][l] = atoi(str2);
            l++;
        }
        if (maxl < l) maxl = l;
    } 
    for (i = 0; i < n; i++) // Сортирует числовые значения в строках
        for (j = 0; j < maxl; j++)
            for (k = j + 1; k < maxl; k++) {
                if (numbers[i][j] == 0)continue;
                if (numbers[i][j] < numbers[i][k]) {
                    x = numbers[i][j];
                    numbers[i][j] = numbers[i][k];
                    numbers[i][k] = x;
                }
            } 
    for (i = 0; i < n; i++) { // Вывод на экран резыльтата сортировки
        printf("\n Строка %d: ", i);
        for (j = 0; j < maxl; j++)
            printf("%d ", numbers[i][j]); 
    }
    free(str);
    free(str2);
    free(numbers);
    return 0;
}
