﻿// + размер вводится
// + тип массива - инт
// + ввод массива с клавиатуры
// + функция инициализации
// + функция вывода
// + функция модификации
// + без всопомгательных массивов
// + удалить все отрицательные элементы, которые не делятся на три и расположены до последнего максимума
// + если подходящих значений нет


#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>


// инициализации массива	
int* def(int* uk, int* ukk) {

	int* B;

	printf("Сколько элементов в массиве?\n ");
	scanf("%d", uk);
	
	// запоминание начального размера массива
	*ukk = *uk;

	// выделение памяти 
	B = (int*) calloc(*uk, sizeof(int));

	printf("\nИнициализируй массив\n");

	// присваивание каждому элементу введеного значения
	for (int i = 0; i < *uk; i++) {
		printf(" B[%d] = ", i);
		scanf("%d", &B [i]);
	}

	return B;
}


// модификация массива
int* mod(int *uB, int *uk) {

	int i, j, maxi = 0, k;

	// поиск индекса последнего максимума
	for (i = 0; i < *uk; i++) {
		if (uB[i] >= uB[maxi]) maxi = i;
	}

	// удаление подходящих элементов
	for (i = 0; i < *uk; i++) {

		// проверка элемента на соответствие требованиям
		if ((uB [i] % 3 != 0) && (i < maxi) && (uB [i] < 0)) {

			k = i;

			// сдвиг элементов влево, если соответствующий не последний
			for (j = k; j < *uk - 1; j++) uB [j] = uB [j + 1];

			maxi--; // уменьшение индекса последнего максимума
			(*uk)--; // уменьшение длины массива

			i--; // уменьшение счетчика, чтобы не пропустить первый сдвинутый элемент
			// перевыделение памяти после удаления
			uB = (int*) realloc(uB, *uk * sizeof(int));
		}

	}

	return uB;
}

// функция выводы массива
void printm(int* uB, int uk) {
	for (int i = 0; i < uk; i++) {
		printf("\n B[%d] = %d", i, uB[i]);
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int uk = 0, ukk = 0;
	int* uB = def(&uk, &ukk);

	uB = mod(uB,&uk);
	// проверка, изменился ли массив
	if (uk == ukk) printf("\n Массив не был модифицирован из-за отсутсвия подходящих значений\n");
	
	printm(uB, uk);

	free(uB);
	return 0;
}