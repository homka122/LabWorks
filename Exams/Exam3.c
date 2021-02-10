#include <stdio.h>
#include <math.h>
#include <stdio.h>

double math_function(double x, double y) {
	return ((1 + sin(x-y) * sin(x-y))/(2 + fabs(x - (2*x)/(1 + x*x*y*y))) + x);
}

void result_math_function(double a, double b, double h, double y) {
	int i;
	printf("|   x    | ");
	for(i = 0; i <= (b - a) / h; i++) {
		printf("%5.2lg | ", a + i*h);
	}
	printf("\n-----------");
	for(i = 0; i <= (b-a)/h; i++) {
		printf("--------");
	}
	printf("\n|   y    | ");
	for(i = 0; i <= (b - a) / h; i++) {
		printf("%5.2lg | ", y);
	}
	printf("\n-----------");
	for(i = 0; i <= (b-a)/h; i++) {
		printf("--------");
	}
	printf("\n| RESULT | ");
	//вывод данных с помощью функции 
	for(i = 0; i <= (b - a) / h; i++) {
		printf("%5.3lg | ", math_function(a + i*h, y));
	}
	printf("\n");
}

int main() {
	double a, b, h, y;
	system("chcp 1251 > nul");
	
	//ввод + проверка
	do {
		printf("¬ведите а и b: ");
		scanf("%lg%lg", &a, &b);
		if (a >= b) {
			printf("права€ граница должна быть больше левой!\n");
		}
	} while(a >= b);
 	do {
 		printf("¬ведите шаг h: ");
 		scanf("%lg", &h);
		if (h <= 0) {
			printf("Ўаг должен быть положительным числом!\n");
		}
	} while(h <= 0);
	printf("¬ведите второй аргумент Y: ");
	scanf("%lg", &y);
	
	result_math_function(a, b, h, y);
	system("pause");
	return 0;
}
