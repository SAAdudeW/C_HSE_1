// (через функцию?) создать вещественный массив из k элементов (элементы вводятся в ручную - цикл с меняющимся индексом элемента)
// (Y ограничивает выборку) найти максимальный по модулю (строгое или нестрогое неравенство) и меньший вводимого Y (2 условия) элемент и вывести значение через функцию
// найти среднее арифметическое всех после первого (не включая) минимального (строгое неравенство) через функцию
// (через функцию?) вывести массив (цикл с меняющимся индексом элемента)

#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>

// функция инициализации массива
float* def(int* uk) {

	float* B;

	printf("Сколько элементов в массиве?\n ");
	scanf("%d", uk);

	// выделение памяти
	B = (float*) calloc(*uk, sizeof(float));

	printf("\nИнициализируй массив\n");

	// присваивание каждому элементу введенного значения
	for (int i = 0; i < *uk; i++) {
		printf(" B[%d] = ", i);
		scanf("%f", &B[i]);
	}

	return B;
}

//функция поиска max
float maxf(float* uB, int uk) {

	float max = -1, Y;

	printf("\n\nВведи |sup| >= 0\n ");
	scanf("%f", &Y);

	// поиск максимального подходящего
	for (int i = 0; i < uk; i++) {
		// проверка на соответствие элемента требованиям
		if ((fabs(uB[i]) >= max) && (fabs(uB[i]) < Y)) {
			max = (float) fabs(uB[i]);
		}
	}

	return max;
}

//функция поиска average
float averagef(float* uB, int uk) {

	int mini = 0;
	float min = uB [0];
	float average = 0;

	// поиск индекса первого минимального
	for (int i = 0; i < uk; i++) {
		if (uB [i] < uB [mini]) {
			mini = i;
		}
	}

	// если первый минимальный - последний в массиве, то просто возврати среднее, не изменяя
	if (mini == (uk - 1)) return average;
	// иначе вычисляется среднее всех, после первого минимального
	else {
		for (int i = mini + 1; i < uk; i++) {
			average = average + uB [i];
		}
		average = average / (float) (uk - 1 - mini);
		return average;
	}

}

// функция выводы массива
void printm(float* uB, int uk) {
	for (int i = 0; i < uk; i++) {
		printf("\n B[%d] = %f", i, uB[i]);
	}
}


int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int uk = 0;
	float* uB = def(&uk);

	float max = maxf(uB, uk);
	double average = averagef(uB, uk);

	// проверка на наличие подходящих элементов
	if (max == -1) printf("\n нет значений, меньших Y по модулю\n ");
	else printf("\n max = %f\n", max);

	if (average == 0) printf("\n минимальный элемент является последним,\n либо сумма всех элементов после минимального равна 0\n");
	else printf("\n average = %f\n", average);

	free(uB);

	return 0;
}


// ++ максимум, когда нет подходящих
// ++ среднее неправильно считается точность сосет
// ++ в ФУНКЦИИ только массив и его длина + нужные 
// создание массива полностью в функции
// обращаться к значению - &n

// функция должна возвращать значение
// если минимальное -- последнее
// if else в main