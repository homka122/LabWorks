#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//abs((fabs(fmod(arr[i], 2)) - 1)
double multi_arr(double *arr, int len) {
	double sum_of_multi = 1;
	int i = 0, flag = 0;
	for (i = 0; i < len; i++) {
		if (fabs((fabs(fmod(arr[i], 2)) - 1)) < 0.000000000001 && arr[i] < 0) {
			sum_of_multi *= arr[i];
			flag = 1;
		}
	}
	if (flag) {
		return sum_of_multi;
	} else {
		return 0;
	}
}

int main() {
	double homka[6] = {-3, -3.00000001, -3, -3, -4.2, 5};
	printf("%lg\n", multi_arr(homka, 6));
	system("pause");
	return 0;
}
