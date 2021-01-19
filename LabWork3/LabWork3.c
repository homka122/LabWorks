#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main() {

	int n, i, count_true = 0, count = 0;
	double A, omega, a = 1, x, y1, y2, s1, s;
	system("chcp 1251 > nul");
	srand(time(0)); // установка для генератора псевдо-случайных чисел

	do {
		system("cls");
		if(a < 0 || a > M_PI) {
			printf("Значение а должно принадлежать отрезку [0;pi]\n");
		}
		printf("Введите А, омегу, а и колличество иттераций: ");
		scanf("%lg%lg%lg%d", &A, &omega, &a, &n);
	} while (a < 0 || a > M_PI);

	// При А = 0 или омега = 0 уравнение не имеет смысла, так как функция превращается в функцию вида y = 0 или y = Asin(a) соответственно
	if (A == 0 || omega == 0) {
		printf("Площадь равна нулю\n");
		system("pause");
		return 0;
	}

	for(i = 0; i < n; i++) {
		x = ((float)rand()/(float)(RAND_MAX)) * (M_PI /  omega); // Рандомный икс, границы которого обусловлены омегой
		y2 = ((float)rand()/(float)(RAND_MAX)) * A; // Рандомный игрек, границы которого обусловлено значением А
		y1 = A * sin(omega * x + a); // Коордианат y функции при значении x
		if (y1 > 0 && A > 0) {
			if (y2 <= y1) {
				count_true++;
			}
		} else if (y1 < 0 && A < 0) {
			if (y2 >= y1) {
				count_true++;
			}
		}
		count++;
	}

	s = fabs(A) * (M_PI / omega); // Вычисление площади
	s1 = ((float)count_true * s) / (float)count;
	printf("Площадь фигуры равна: %lg.\n", s1);

	system("pause");
	return 0;
}
