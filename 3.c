#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	double x, acc, ss = 1, sss = 10, sf, slagF, slagS, otn;
	int n = 1, m, c;

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	printf("Введи вещественное x такое, что |x| < 1\n");
	scanf("%lf", &x);
	printf(" x = %lf\n\n", x);

	sf = 1 / sqrt(1 + x);
	printf("Значение левой части равенства\n sf = %lf\n\n", sf);

	// выбор способа решения
	printf("Введи '1' или '2' для выбора способа решения\n");
	scanf("%d", &c);
	printf(" c = %d\n\n", c);

	slagF = -1 * x * 1 / 2;
	ss = ss + slagF;

	switch (c)
	{
		case 1:
		{
			// задавание точности, с которой будет вычисляться правая часть равенства
			printf("Задай точность вычисления\n");
			scanf("%lf", &acc);
			printf(" acc = %lf\n\n", acc);

			printf("Все значения правой части равенства, включая промежуточные\n");

			for ( ; ; ) {
				if (fabs(sss - ss) < acc) {
					break;
				}

				sss = ss;

				otn = (-1 * x) / ((double)2 * n + 2) * ((double)2 * n + 1); // отношение слагаемого от (n+1) к слагаемому от n
				slagS = slagF * otn;

				// вычисление правой части равенства
				ss = ss + slagS;
				slagF = slagS;

				printf(" ss = %lf\n", ss);
				n = n + 1;
			}
		} break;

		case 2:
		{
			printf("Введи натуральное m, определяющее, сколько раз выполнится цикл\n");
			scanf("%d", &m);
			printf(" m = %d\n\n", m);

			printf("Все значения правой части равенства, включая промежуточные\n");

			do {
				otn = (-1 * x) / ((double)2 * n + 2) * ((double)2 * n + 1); // отношение слагаемого от (n+1) к слагаемому от n
				slagS = slagF * otn;

				// вычисление правой части равенства
				ss = ss + slagS;
				slagF = slagS;

				printf(" ss = %lf\n", ss);
				n = n + 1;
			} while (n <= m);
		} break;
	}
	return 0;
}
