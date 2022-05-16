/* Следует выделять для строки на 1 ячейку памяти больше,
чем предполагается ввести символов,
из - за автоматически добавляющегося "нулевого байта" ('\0')
Если введено больше, чем выделено памяти,
то введенное частично займет чужую память */

/* scanf("%s", a) останавливается на первом пустом символе(пробел, переход на новую строку и т.д.)
ввод строки gets(a)
ввод символа getchar() (возвращает значение введенного символа) */

/* вывод printf("%s", a)
puts(a) (вторая, в дополнение, переходит на новую строчку) 
вывод символа putchar() (возвращает значение выводимого символа) */

/* strtok(char* str, char* sep) возвращает указатель на первый символ из str, но не из sep.
В случае провала, возвращает NULL.
При повторном применении (NULL, sep), так как функция запоминает место остановки,
то есть первого символа-разделителя, и автоматически переходит на место сразу после него.
Заменяет первый встреченный символ-разделитель на \0, преобразуя строку */

/* от 1 до 30 слов до 10 латинских букв или цифр в каждом
между словами не менее 1 пробела, после последнего слова точка
напечатать все слова, отличные от последнего,
предварительно поменяв в них местави первый наибольший и первый наименьший (по коду) символы */

/* ? проверка ввода
? какой размер */ 

// 26Aleksandr Shalaginov12 20Antonovich02 20Antonovich02. 123rfd3erhrt5

/* #define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// вывести и преобразовать все слова, не равные последнему
void mod(char strM[350]) {

	int i, j, c = 0, e = 0, imax, imin;
	char smax, smin;
	char* word;
	char* words[30];
	char* wordv;

	// разбиение строки на слова
	printf("\n");
	word = strtok(strM, " "); // выделение первого слова
	if (word != NULL) {

		while (word [strlen(word) - 1] != '.') {

			words [c] = word; c++; // заполнение свободного массива из строк словами
			puts(word); // вывод выделенного слова
			wordv = strtok('\0', " "); // выделение следующего слова

			if (wordv != NULL) word = wordv;
			else break;

		}

		word [strlen(word) - 1] = '\0'; // замена точки (последнего символа) в последнем слове на '\0'
		words [c] = word; c++; // размещение в свободном массиве последнего слова
		puts(word); // вывод последнего слова

		printf("\n Слов выделено: c = %d\n", c); // вывод количества выделенных слов

		// преобразование соответствующих слов
		for (i = 0; i < c - 1; i++) {

			/* проверка на полное совпадение проверяемого слова с последним
			for (j = 0; words [i][j] != '\0'; j++) {
				if (words [i][j] == words [c - 1][j]) e++;
				else continue;
			}

			// модивикация соответствующих слов
			if ((e != j) || (strlen(words [i]) != strlen(words [c - 1]))) { */

/*			if (strcmp(words[i], words[c - 1])) { // проверка на совпадение слова с последним

				printf("\n");
				puts(words [i]); // вывод соответствующего слова до изменения

				smax = '\0'; imax = 0;
				smin = words [i][0]; imin = 0;
				for (j = 0; words [i][j] != '\0'; j++) {
					if (words [i][j] > smax) { // поиск наибольшего символа
						smax = words [i][j]; imax = j;
					}
					if ((words [i][j] < smin) && (words [i][j] != '\0')) { // поиск наименьшего символа
						smin = words [i][j];
						imin = j;
					}
				}
				printf(" smax = %c smin = %c\n", smax, smin); // вывод соответствующих символов

				words [i][imin] = smax; words [i][imax] = smin; // перестановка соответствующих символов

				puts(words [i]); // вывод соответствующего слова после изменения


			}

			// e = 0; // обнуления счетчика совпадения
		}

		// сумма цифр в каждом слове
		int sum = 0;
		for (i = 0; i < c; i++) {
			printf("\n");
			for (j = 0; words[i][j] != '\0'; j++) {
				if ((words[i][j] >= '0') && (words[i][j] <= '9')) {
					printf("%c ", words [i][j]);
					sum = sum + (int)(words[i][j] - '0');
				}
			}
			printf("\nsum[%d] = %d", i, sum);
			sum = 0;
		}

	}
	else printf("\n Слов нет\n ");
}


/* проверка на последнее слово, если в разбиении учитывается точка

*/

/*
// вывести и преобразовать все слова, кроме последнего
void mod(char* strM) {

	int i, imax, imin, c = 1;
	char smax, smin;
	char* word;

	printf("\n");
	word = strtok(strM, " "); // выделение первого слова
	while (word != NULL) {

		for (i = 0; word [i] != '\0'; i++) { // проверка, является ли слово последним
			if (word [i] == '.') c = 0;
		}
		printf("\nc = %d\n", c);

		if (c != 0) { // модификация соответствующих слов

			puts(word); // вывод соответствующего слова до изменения
			smax = '\0'; imax = 0;
			smin = word [0]; imin = 0;
			for (i = 0; word [i] != '\0'; i++) {
				if (word [i] > smax) { // поиск наибольшего символа
					smax = word [i]; imax = i;
				}
				if ((word [i] < smin) && (word [i] != '\0')) { // поиск наименьшего символа
					smin = word [i];
					imin = i;
				}
			}
			printf(" smax = %c\n smin = %c", smax, smin); // вывод соответствующих символов

			word [imin] = smax; word [imax] = smin; // перестановка соответствующих символов

			printf("\n"); puts(word); printf("\n"); // вывод соответствующего слова после изменения

		}
		else break;

		word = strtok('\0', " "); // выделение следующего слова
		c = 1;	

	}

}
*/


#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// вывести и преобразовать все слова, не равные последнему
void mod(char strM [350]) {

	int i, j, c = 0, imax, imin;
	char smax, smin;
	char* word;
	char* words [30];
	char* wordv;

	// разбиение строки на слова
	printf("\n");
	word = strtok(strM, " "); // выделение первого слова
	if (word != NULL) {

		while (word [strlen(word) - 1] != '.') {

			words [c] = word; c++; // заполнение свободного массива из строк словами
			puts(word); // вывод выделенного слова
			wordv = strtok('\0', " "); // выделение следующего слова

			if (wordv != NULL) word = wordv;
			else break;

		}

		word [strlen(word) - 1] = '\0'; // замена точки (последнего символа) в последнем слове на '\0'
		words [c] = word; c++; // размещение в свободном массиве последнего слова
		puts(word); // вывод последнего слова

		printf("\n Слов выделено: c = %d\n", c); // вывод количества выделенных слов

		// преобразование соответствующих слов
		for (i = 0; i < c - 1; i++) {

			if (strcmp(words [i], words [c - 1])) { // проверка на совпадение слова с последним

				printf("\n");
				puts(words [i]); // вывод соответствующего слова до изменения

				smax = '\0'; imax = 0;
				smin = words [i][0]; imin = 0;
				for (j = 0; words [i][j] != '\0'; j++) {
					if (words [i][j] > smax) { // поиск наибольшего символа
						smax = words [i][j]; imax = j;
					}
					if ((words [i][j] < smin) && (words [i][j] != '\0')) { // поиск наименьшего символа
						smin = words [i][j];
						imin = j;
					}
				}
				printf(" smax = %c smin = %c\n", smax, smin); // вывод соответствующих символов

				words [i][imin] = smax; words [i][imax] = smin; // перестановка соответствующих символов

				puts(words [i]); // вывод соответствующего слова после изменения


			}

		}

	}
	else printf("\n Слов нет\n ");
}

int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	char str[350];
	gets_s(str, 350);
	printf("\n Введено:\n"); puts(str);

	char strM[350]; strcpy(strM, str);

	mod(strM);

	printf("\n\n"); puts(str);

	return 0;
}