﻿#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// + функция формирования исходного файла с действительными числами
// + функция вывода результата работы программа
// + функция задания
/* + поиск наименьшего по модулю числа с четным номером
+ записать найденное значение после числа с номером N */

// элементов не становится больше - последний теряется, зато сохраняется в a или b

/* тесты
+ минимальный по модулю четный
+ минимальный по модулю нечетный
+ минимальный по модулю нулевой
+ 1 элемент 
+ несколько минимальных по модулю вставка после всех?
+ недопустимый номер вставки
+ ввод и вставка по номеру, а не по счету
+ вставка после последнего
*/

void def(char* address) { // функция формирования исходного файла

	FILE* f = fopen(address, "wb"); // открытия потока для записи в бинарный файл
	if (f != NULL) { // есди успешно открылся

		int n = 0;
		printf(" Введи количество элементов: ");
		scanf("%d", &n);
		printf("\n");
		double e;
		for (int i = 0; i < n; i++) { // почленная запись вводимых чисел в файл
			printf(" Введи %dый элемент: ", i);
			scanf("%lf", &e);
			fwrite(&e, sizeof(double), 1, f);
		}

		fclose(f); // закрытие потока
	}
	else printf("Не удалось открыть файл для записи");

}

void task(char* address) {

	int n = 0, imin;
	double min;

// поиск наименьшего по модулю с четным номером

	FILE* f = fopen(address, "rb"); // открытие потока для чтения из бинарного файла
	if (f != NULL) { // если успешно открылся

		printf("\n");
		double e;
		while (!feof(f)) { // пока файл не кончится

			fread(&e, sizeof(double), 1, f); // чтение из файла числа в переменную e
			if (!feof(f)) { // если файл не кончился

				if (n == 0) { // присваивание параметров первого элемента параметрам минимума
					min = fabs(e);
					imin = 1;
				}
				if ((min > fabs(e)) && (n % 2 == 0)) { // поиск минимального по модулю с четным номером
					min = fabs(e);
					imin = n;
				}

				n++;
			}

		}

		fclose(f); // закрытие потока
		printf(" Минимальное по модулю значение с четным номером %d: %lf\n", imin, min);
	}
	else printf("Неудалость открыть файл для чтения");

// ДОП СКОЛЬКО РАЗ ВСТРЕЧАЕТСЯ МИНИМУМ. ЗАПИСАТЬ В КОНЕЦ ФАЙЛА
	int k = 0;
	double r;
	f = fopen(address, "r +b"); // открытиче на чтение + запись существующего бинарного файла
	if (f != NULL) { // если открылось успешно

		while (!feof(f)) {
			fread(&r, sizeof(double), 1, f);
			if (fabs(r) == min) {
				k++;
			}
		}
		fflush(f);
		fseek(f, 0, SEEK_END);
		fwrite(&min, sizeof(double), 1, f);
		printf("\n Минимальное значение встречается %d раз\n", k);
	}
	else printf("Не удалось открыть файл");
// КОНЕЦ ДОП

// раздвиг-освобождение N+1 места и размещение в нем min
	int N;
	printf("\n Введи номер элемента, после которого вставить найденное значение: ");
	scanf("%d", &N);

	double a, b;
	int codEnd;

	f = fopen(address, "r +b"); // открытиче на чтение + запись существующего бинарного файла
	if (f != NULL) { // если открылось успешно

		fseek(f, (long)N * (long)sizeof(double), SEEK_SET); // переход к месту раздвига
		// указатель между элементами N и N-1
		fread(&a, sizeof(double), 1, f); // запись элемента N в a
		if (!feof(f)) { // если не конец файла
			fread(&b, sizeof(double), 1, f); // запись элемента N в b
			if (!feof(f)) { // если не конец файла

				fflush(f); // очистка буфера перед сменой направления

				// fseek(f, (long) (N + 1) * (long) sizeof(double), SEEK_SET); // смещение к между N и N+1
				// fwrite(&a, sizeof(double), 1, f); // запись a в f

				fseek(f, (long)(N + 1) * (long) sizeof(double), SEEK_SET); // смещение к между N и N+1
				fwrite(&min, sizeof(double), 1, f); // // запись min в f

				int i;
				for (i = 1; ; i++) {
					if (i % 2 == 1) { // если индекс (номер операции) нечетный
						fflush(f); // очистка буфера перед сменой направления
						fread(&a, sizeof(double), 1, f); // запись элемента в a
						if (!feof(f)) { // если не конец файла
							fflush(f); // очистка буфера перед сменой направления
							fseek(f, (long) (-1) * (long) sizeof(double), SEEK_CUR); // смещение на одно место назад от текущего
							fwrite(&b, sizeof(double), 1, f); // запись b в f
						}
						else { // если конец файла
							codEnd = 1; // последнее число в b, предпоследнее - в a
							break;
						}
					}
					else { // если индекс (номер операции )четный 
						fflush(f); // очистка буфера перед сменой направления
						fread(&b, sizeof(double), 1, f); // запись элемента N в b
						if (!feof(f)) { // если не конец файла
							fflush(f); // очистка буфера перед сменой направления
							fseek(f, (long) (-1) * (long) sizeof(double), SEEK_CUR); // смещение на одно место назад от текущего
							fwrite(&a, sizeof(double), 1, f); // запись a в f
						}
						else { // если конец файла
							codEnd = 2; // последнее число в a, предпоследнее - в b
							break;
						}
					}
				}

			}
			else codEnd = 3; // послепоследнее в b, последнее - в a. Вставка после последнего
		}

		switch (codEnd) {

			case 1:
				fflush(f); // очистка буфера перед сменой направления
				fseek(f, (long)(-1) * (long)sizeof(double), SEEK_END); // смещение на одно место назад от конца
				fwrite(&a, sizeof(double), 1, f); // запись a в f
				fwrite(&b, sizeof(double), 1, f); // запись b в f
			break;

			case 2:
				fflush(f); // очистка буфера перед сменой направления
				fseek(f, (long) (-1) * (long) sizeof(double), SEEK_END); // смещение на одно место назад от конца
				fwrite(&b, sizeof(double), 1, f); // запись b в f
				fwrite(&a, sizeof(double), 1, f); // запись a в f
			break;

			case 3:
				fflush(f); // очистка буфера перед сменой направления
				fseek(f, 0, SEEK_END); // смещение в конец
				fwrite(&min, sizeof(double), 1, f); // запись min в f
			break;
		}

		fclose(f); // закрытие потока
	}
	else printf("Не удалось открыть файл");
	
}


void outf(char* address) { // функция вывода результата работы программы

	FILE* f = fopen(address, "rb"); // открытие потока для чтения из бинарного файла
	if (f != NULL) { // если успешно открылся

		printf("\n");
		double e;
		int n = 0;
		while (!feof(f)) { // пока файл не кончится

			fread(&e, sizeof(double), 1, f); // чтение из файла числа в переменную e
			if (!feof(f)) { // если файл не кончился
				printf(" %dый элемент: ", n);
				printf("%lf\n", e); // вывод считанного числа
			}

			n++;
		}

		printf("\n");
		fclose(f); // закрытие потока
	}
	else printf("Неудалость открыть файл для чтения");

}

int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	char address[] = "f10.bin";
	def(address);
	task(address);
	outf(address);
	return 0;
}

// массивов быть не должно. ВСЕ В ФАЙЛЕ
// + передача в функцию

// ДОП СКОЛЬКО ВСТРЕЧАЕТСЯ МИНИМАЛЬНОЕ ЗНАЧЕНИЯ МОДУЛЯ И ДОПИСАТЬ ЕГО В КОНЕЦ









// вставка найденного значения после элемента с номером N в файл
/*

fflush(FILE *stream);

перейти через fseek к месту нужному
раздвинуть
	первый шаг i = 0
		записываю текущее значение в переменную 1
		записываю следующее значение в переменную 2
		записываю переменную 1 в следующее значение
	следующие шаги i = 1, 3, 5,..
		записываю следующее значение в переменную 1
		записываю переменную 2 в следующее значение
	послеследующие шаги i = 2, 4 , 6,..
		записываю следующее значение в переменную 2
		записываю переменную 1 в следующее значение

перейти через fseek к месту нужному
вставить

*/









/*
void task(FILE* f) {

	double* E = NULL;
	int n = 0;

// чтение из файла в массив
	f = fopen(FILE_NAME, "rb"); // открытие потока для чтения из бинарного файла

	if (f != NULL) { // если успешно открылся

		printf("\n");
		double e;
		while (!feof(f)) { // пока файл не кончится

			fread(&e, sizeof(double), 1, f); // чтение из файла числа в переменную e
			if (!feof(f)) {
				n++;
				E = realloc(E, sizeof(double) * n);
				E[n-1] = e; // заполнение массива элементами из файла
			}

		}
		fclose(f); // закрытие потока

	}
	else printf("Неудалость открыть файл для чтения");

// поиск наименьшего по модулю числа с четным номером
	int i, im = 0;
	double m = fabs(E[0]);
	for (i = 1; i < n; i++) {
		if ((fabs(E [i]) < m) && (i % 2 == 0)) { // проверка номера и модуля
			m = fabs(E [i]);
			im = i;
		}
	}
	printf(" Минимальное по модулю значение с четным номером %d: %lf\n", im, m);

// вставка найденного значение после элемента с номером N в массив
	int N;

	printf("\n Введи номер элемента, после которого вставить найденное значение: ");
	scanf("%d", &N);

	while (N > (n-1)) { // > n-1
		printf("\nВведено недопустимое значение!\n");
		scanf("%d", &N);
	}

	E = realloc(E, sizeof(double) * (n + 1));
	for (i = n; i > (N-1); i--) {
		E [i] = E [i - 1];
	}
	E [N] = m;

// запись измененного массива обратно в файл
	f = fopen(FILE_NAME, "wb"); // открытия потока для записи в бинарный файл

	if (f != NULL) { // если успешно открылся

		for (int i = 0; i < n + 1; i++) { // почленная запись введенных чисел в файл
			fwrite(&E [i], sizeof(double), 1, f);
		}
		fclose(f); // закрытие потока

	}
	else printf("Не удалось открыть файл для записи");

}
*/

// вставка найденного значение после элемента с номером N в массив
	/*
	int N;

	printf("\n Введи номер элемента, после которого вставить найденное значение: ");
	scanf("%d", &N);

	while (N > (n - 1)) { // > n-1
		printf("\nВведено недопустимое значение!\n");
		scanf("%d", &N);
	}

	E = realloc(E, sizeof(double) * (n + 1));
	for (i = n; i > (N - 1); i--) {
		E [i] = E [i - 1];
	}
	E [N] = m;

// запись измененного массива обратно в файл
	f = fopen(FILE_NAME, "wb"); // открытия потока для записи в бинарный файл

	if (f != NULL) { // если успешно открылся

		for (int i = 0; i < n + 1; i++) { // почленная запись введенных чисел в файл
			fwrite(&E [i], sizeof(double), 1, f);
		}
		fclose(f); // закрытие потока

	}
	else printf("Не удалось открыть файл для записи");
	*/