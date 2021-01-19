#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

	system("chcp 1251 > nul");


	double x, y, c;
	printf("Введите x и y: ");
	scanf("%lf%lf", &x, &y);

	c = (3.0 + exp(y - 1.0)) / (1.0 + x*x*fabs(y - tan(x)));

	printf("Результат функции при X = %lg и Y = %lg равен: %0.5f\n", x, y, c);

	system("pause");
	return 0;
}
