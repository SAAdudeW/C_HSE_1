#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {

		// определение переменных
	signed int x, y; // целых знаковых
	float z; // вещественной
	double a, achisl, aznam, b; // вещественных двойной точности

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

		// инициализация переменных
	printf("Введи целое x\n "); scanf("%d", &x);
	printf("\nВведи целое y\n "); scanf("%d", &y);
	printf("\nВведи вещественное z\n "); scanf("%f", &z);

	printf("\nВывод введенных x, y в в десятичном целочисленном формате, \nz в экспоненциальной форме с точностью 5 знаков после десятичного разделителя\n x = %10d\n y = %10d\n z = %10.5e\n", x, y, z);

	achisl = cbrt(fabs((double)y - (double)2 * x));
		// achisl = кубический корень из |y-2*x|
	aznam = sqrt(cos(2 * pow((double)x, 3)-7))-3.4;
		// aznam = квадратный корень из разности косинуса (2*x^3-7) и 3.4

	a = achisl / aznam;
 
	b = atan2(((double)2 * x), (fabs((double)3 * z - 1) + 4));
		// b = арктангенс частного (2*x) и (|3*z-1|+4)

	printf("\nВывод a и b в десятичном формате с точностью 4 знака после десятичного разделителя\n a = %.4f\n b = %.4f\n", a, b);

	printf("\nВывод x восьмеричном и y в шестнадцатеричном представлениях\n x = %o\n y = %x", x, y);

	return 0;
}