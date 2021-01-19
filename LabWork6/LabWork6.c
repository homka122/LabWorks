#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Ввод значений
int inputArr();
//Заполнение массива с помощью ввода значений
void fillArr(double *numbers, int len);
//Сортировка массива с помощью сортировки пузырьком
void sortArrPuzirik(double *numbers, int len);
// Является ли данный массив арифметической прогрессией с шагом diff
int isTrueArr(double *numbers, int len, double diff);

main() {
	int isTrue = 1, len;
	double numbers[20], diff;
	system("chcp 1251 > nul");

	len = inputArr();

	printf("Введите значения массива: ");
	fillArr(numbers, len);
	sortArrPuzirik(numbers, len);
	diff = numbers[1] - numbers[0];
	isTrue = isTrueArr(numbers, len, diff);

	if(isTrue) {
		printf("Введенные элементы являются членами арифметической прогрессии с шагом %lg по модулю\n", diff);
	} else {
		printf("Это не арифметическая прогрессия\n");
	}

	system("pause");
	return 0;
}

int inputArr() {
	double len;
	while(1) {
		printf("Введите размер массива: ");
		scanf("%lg", &len);
		if (len <= 1 || len > 20 || round(len) != len) {
			system("cls");
			printf("Количество элементов массива должно быть целым положительным числом больше одного и не больше двадцати!\n");
			continue;
		}
		break;
	}
	return (int)len;
}

void fillArr(double *numbers, int len) {
	int i;
	for(i = 0; i < len; i++) {
		scanf("%lg", &numbers[i]);
	}
}

void sortArrPuzirik(double *numbers, int len) {
	int i, j;
	double diff;
	// сортировка методом пузырька
	for(i = 0; i < len; i++) {
		for(j = 0; j < len - i - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				diff = numbers[j + 1];
				numbers[j+1] = numbers[j];
				numbers[j] = diff;
			}
		}
	}
}

int isTrueArr(double *numbers, int len, double diff) {
	int isTrue = 1, i;
	// Определение разницы между двумя соседними числами. В арифметической прогрессии
	// эта разница будет одинакова при любых разностях соседних чисел ариф. прогрес.
	for(i = 1; i < len - 1; i++) {
		if (fabs((numbers[i + 1] - numbers[i]) - diff) > 0.00001) { // Так как нельзя использовать == с double числами, я применил альтернитиву
			isTrue = 0; //isTrue - истина, если это ариф. прогрес., ложь, если нет
			break;
		}
	}
	return isTrue;
}
