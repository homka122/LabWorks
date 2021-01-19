#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	system("chcp 1251 > null");
	
	printf("Введите три положительных числа a, b, c: ");
	scanf("%d%d%d", &a, &b, &c);
	
	if (a < 0 || b < 0 || c < 0) {
		printf("Неправильный ввод. Все введенные значения должны быть положительными!\n");
	} else {
		// В первом случае a < b. Во втором случае b < a. Исходя из этих данных мы сравниваем [с] с другими переменными.
		if ((a < c && c < b && a < b) || (b < c && c < a && b < a)) {
			printf("Число %d находится между числами %d и %d.\n", c, a < b ? a : b, a < b ? b : a);
		} else {
			printf("Число %d не находится между числами %d и %d.\n", c, a < b ? a : b, a < b ? b : a);
		}
	}
	
	system("pause");
	return 0;
}
