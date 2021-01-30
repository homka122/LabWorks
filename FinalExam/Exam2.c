#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 12

void sort_of_coord_arr(double *arr, int len) {
	int i, j;
	double num1, num2, temp;
	
	if (len % 2 != 0) {
		printf("Массив не может быть отсортирован, потому что одно число без пары\n");
		return 0;
	}
	
	for(i = 0; i < len/2; i++) {
		for(j = 0; j < len/2 - i - 1; j++) {
			// len = 8, len/2 = 4
			num1 = arr[j*2]*arr[j*2] + arr[j*2+1]*arr[j*2+1];
			num2 = arr[j*2+2]*arr[j*2+2] + arr[j*2+3]*arr[j*2+3];
			if (num2 < num1) {
				temp = arr[j*2];
				arr[j*2] = arr[j*2+2];
				arr[j*2+2] = temp;
				temp = arr[j*2+1];
				arr[j*2+1] = arr[j*2+3];
				arr[j*2+3] = temp;
			}
		}
	}
}

int main() {
	int i;
	double homka[SIZE] = {2, 3, 2, 1, 40, 20, 4, 0, 4, 5, 3, 1};
	
	system("chcp 1251 > nul");
	
	//вывод массива до измненений
	for(i = 0; i < SIZE; i++) {
		printf("%lg ", homka[i]);
		if (i % 2 != 0) {
			printf(" ");
		}
	}
	printf("\n");
	sort_of_coord_arr(homka, SIZE);
	
	//вывод массива после изменений
	for(i = 0; i < SIZE; i++) {
		printf("%lg ", homka[i]);
		if (i % 2 != 0) {
			printf(" ");
		}
	}
}
