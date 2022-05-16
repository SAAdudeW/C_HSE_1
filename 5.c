#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

// инициализация массива (m >= 2, n <= 10)
int* def(int* m, int* n) {

	int* W;

	printf(" сколько строк? m = "); scanf("%d", m);
	printf(" сколько столбцов? n = "); scanf("%d", n); printf("\n");

	// выделение памяти на матрицу
	W = (int*) calloc(*m * *n, sizeof(int));

	// присваивание каждому элементу введенного значения
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			printf(" w[%d][%d] = ", i, j);
			scanf("%d", (W + i * *m + j));
		}
	}

	return W;
}

// поиск среднего арифметического максимальных элементов диагоналей, расположенных выше и ниже побочной (только для квадратной матрицы)
double af(int* w, int m, int n) {

	int b, c;
	int i, j;
	double a = 0;

	// поиск максимального элемента в диагонали над побочной
	b = *(w + (m - 2) * m + 0);
	for (i = m - 2, j = 0; i >= 0, j <= n - 2; i--, j++) {
			if (*(w + i * m + j) > b) b = *(w + i * m + j);
	}

	// поиск максимального элемента в диагонали под побочной
	c = *(w + (m - 1) * m + 1);
	for (i = m - 1, j = 1; i >= 1, j <= n - 1; i--, j++) {
			if (*(w + i * m + j) > c) c = *(w + i * m + j);
	}

	// вычисление среднего арифметического b и c
	a = ((double)b + (double)c) / (double)2;
	return a;
}

// функция вывода массива
void printW(int* w, int m, int n) {
	
	printf("\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf(" w[%d][%d] = %d ", i, j, *(w + i * m + j));
		}
		printf("\n");
	}
} 


int main() {	

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int m = 0, n = 0;
	int* w = def(&m, &n);

	printW(w, m, n);	
	printf("\n average = %lf\n", af(w, m, n));

	free(w);

return 0;
}

// адрес массива должен передаваться, как параметр функции
// создание массива полностью в функции (ввод элементов, их количевства, выделение памяти)
// ++ af возвр значение

/*

max = *(w + 0 * m + 0);
for (i = 0, i < m; i++) {
	for (j = 0, j < n; j++) {
		if (*(w + i * m + j) > max) max = *(w + i * m + j);
	}
}

*/	

// массив должен быть квадратный?
// для решения проблем с памятью есть ограничение <= 10?

// в main только операторы вызова функций
// адрес массива передается как параметр функции
// без дополнительных массивов