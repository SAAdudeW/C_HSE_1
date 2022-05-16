/* #define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// + сформировать массив из записей с заданной структурой заданной длины <=20
/* + структуры определять в отдельных заголовочных файлах */
/*  +- с помощью директив условной компиляции определить 2 способа ввода исходного массива структур :
+ пользователем с потока ввода
+- из заранее заполненого массива * /
/* служащий - фио, год рождения, адрес
фио - фамилия, имя, отчество
адрес - улица, номер дома, номер кв */
// + вывести на экран
// + найти номер дома и квартиры служащих определенного года рождения проживающих на заданной улице

// ? переопределение в готовом случае

/* #include "address.h"
#include "fio.h"
#include "rank.h" */

/* void in(RANK STR[20], int* k) { // функция ручного ввода массива структур

	int i;


	printf("Сколько служащих? "); scanf("%d", k);

	for (i = 0; i < *k; i++) { 

		STR [i].fio.surname = calloc(20, sizeof(char)); // ввод фамилии
		printf("\n Фамилия: ");
		getchar(); gets_s(STR [i].fio.surname, 20);
			STR [i].fio.name = calloc(20, sizeof(char)); // ввод имени
			printf(" Имя: ");
			gets_s(STR [i].fio.name, 20);
		STR [i].fio.fathername = calloc(20, sizeof(char)); // ввод отчества
		printf(" Отчество: ");
		gets_s(STR [i].fio.fathername, 20);
			printf(" Год рождения: "); // ввод года рождения
			scanf("%d", &(STR[i].bd));
		STR [i].address.st = calloc(20, sizeof(char)); // ввод улицы
		printf(" Улица: ");
		getchar(); gets_s(STR [i].address.st, 20);
			printf(" Номер дома: "); // ввод номера дома
			scanf("%d", &(STR[i].address.hn));
		printf(" Номер квартиры: "); // ввод номера квартиры
		scanf("%d", &(STR[i].address.fn));
	}

}

void task(RANK STR[20], int k) { // функция поиска по запросу

	int y; // ввод года сортировки
		printf("\n Год сортировки: ");
		scanf("%d", &y);
	char w[20]; // ввод улицы сортировки
		printf(" Улица сортировки: ");
		getchar(); gets_s(w, 20);

	int i, j, c = 0, e = 0;

	for (i = 0; i < k; i++) {

		/* if (strlen(STR[i].address.st) == strlen(w)) {

			for (j = 0; STR[i].address.st[j] != '\0'; j++) {
				if (STR [i].address.st [j] == w [j]) e++;
				else continue;
			}
			if (e == j) {

			if ((STR [i].bd == y) && (!strcmp(STR [i].address.st, w))) {
				printf("\n Квартира %d в доме %d", STR [i].address.fn, STR [i].address.hn);
				c++;
			}
			else continue;

				if ((STR [i].bd == y) && (*(STR [i].address.st) == *w)) {
					printf("\n Квартира %d в доме %d", STR [i].address.fn, STR [i].address.hn);
					c++;
				}
				else continue;

			}
			e = 0;

		} */

/*		if ((STR[i].bd == y) && (!strcmp(STR[i].address.st, w))) { // проверка на совпадение просматриваемых улицы и года заданным параметрам сортировки
			printf("\n Квартира %d в доме %d", STR [i].address.fn, STR [i].address.hn);
			c++; // изменение счетчика найденных совпадений
		}
		else continue;

	}
	if (c == 0) {
		printf("\n Не найдено совпадений");
	}

	int cc = 0, year;
	printf("\n\nДополнительный год сортировки: ");
	scanf("%d", &year);
	for (i = 0; i < k; i++) {
		if (STR [i].bd == year) {
			cc++;
		}
	}
	printf("Служащих заданного дополнительного %d года %d", year, cc);

}

void out(RANK STR[20], int k) { // функция вцывода массива структур

	int i;

	printf("\n");

	for (i = 0; i < k; i++) { // цикл вывода каждой структуры поэлементно
		printf("\n Служащий %d: %s %s %s %d, %s %d %d", i, STR [i].fio.name, STR [i].fio.surname, STR [i].fio.fathername, STR [i].bd, STR [i].address.st, STR [i].address.hn, STR [i].address.fn);
	}

}

int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int k = 0;
	RANK STR[20];

	#define CHOICE 1 // директива, заменяющая константу CHOICE на значение переменной choice
	#if CHOICE // ветка, выполняющая при choice != 0
		k = 10;
		#include "data.h" // включение файла с объявлением и инициализацией готовой базы DATA
		#define STR DATA // директива, заменяющая STR на DATA вместо присваивания "STR = DATA"
	#else // ветка, выполняющаяся при choice == 0
		in(STR, &k);
	#endif // конец условной компиляции

	task(STR, k);
	out(STR, k);

	return 0;
} */

// посчитать всех, которые заданного года рождения

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "address.h"
#include "fio.h"
#include "rank.h"

void in(RANK STR [20], int* k) { // функция ручного ввода массива структур

	int i;


	printf("Сколько служащих? "); scanf("%d", k);

	for (i = 0; i < *k; i++) {

		STR [i].fio.surname = calloc(20, sizeof(char)); // ввод фамилии
		printf("\n Фамилия: ");
		getchar(); gets_s(STR [i].fio.surname, 20);
			STR [i].fio.name = calloc(20, sizeof(char)); // ввод имени
			printf(" Имя: ");
			gets_s(STR [i].fio.name, 20);
		STR [i].fio.fathername = calloc(20, sizeof(char)); // ввод отчества
		printf(" Отчество: ");
		gets_s(STR [i].fio.fathername, 20);
			printf(" Год рождения: "); // ввод года рождения
			scanf("%d", &(STR [i].bd));
		STR [i].address.st = calloc(20, sizeof(char)); // ввод улицы
		printf(" Улица: ");
		getchar(); gets_s(STR [i].address.st, 20);
			printf(" Номер дома: "); // ввод номера дома
			scanf("%d", &(STR [i].address.hn));
		printf(" Номер квартиры: "); // ввод номера квартиры
		scanf("%d", &(STR [i].address.fn));
	}

}

void task(RANK STR [20], int k) { // функция поиска по запросу

	int y; // ввод года сортировки
	printf("\n Год сортировки: ");
	scanf("%d", &y);
	char w [20]; // ввод улицы сортировки
	printf(" Улица сортировки: ");
	getchar(); gets_s(w, 20);

	int i, j, c = 0, e = 0;

	for (i = 0; i < k; i++) {

		if ((STR [i].bd == y) && (!strcmp(STR [i].address.st, w))) { // проверка на совпадение просматриваемых улицы и года заданным параметрам сортировки
			printf("\n Квартира %d в доме %d", STR [i].address.fn, STR [i].address.hn);
			c++; // изменение счетчика найденных совпадений
		}
		else continue;

	}
	if (c == 0) {
		printf("\n Не найдено совпадений");
	}

}

void out(RANK STR [20], int k) { // функция вцывода массива структур

	int i;

	printf("\n");

	for (i = 0; i < k; i++) { // цикл вывода каждой структуры поэлементно
		printf("\n Служащий %d: %s %s %s %d, %s %d %d", i, STR [i].fio.name, STR [i].fio.surname, STR [i].fio.fathername, STR [i].bd, STR [i].address.st, STR [i].address.hn, STR [i].address.fn);
	}

}

int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int k = 0;
	RANK STR [20];

#define CHOICE 0 // директива, заменяющая константу CHOICE на значение переменной choice
#if CHOICE // ветка, выполняющая при choice != 0
	k = 10;
#include "data.h" // включение файла с объявлением и инициализацией готовой базы DATA
#define STR DATA // директива, заменяющая STR на DATA вместо присваивания "STR = DATA"
#else // ветка, выполняющаяся при choice == 0
	in(STR, &k);
#endif // конец условной компиляции

	task(STR, k);
	out(STR, k);

	return 0;
}