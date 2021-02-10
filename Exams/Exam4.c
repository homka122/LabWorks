#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input_len() {
    double len;
    while(1) {
        printf("Введите кол-во элементов: ");
        scanf("%lg", &len);
        fflush(stdin);
        if ((int)len != len || len <= 0 || len > 20) {
            printf("Кол-во элементов - целое число в интервале [1, 20]\n");
            continue;
        }
        break;
    }
    return (int)len;
}

void fill_array(double *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("Arr[%d] = ", i);
        scanf("%lg", &arr[i]);
    }
}

void show_array(double *arr, int len) {
    int i;
    printf("Arr = [");
    for(i = 0; i < len-1; i++) printf("%lg, ", arr[i]);
    printf("%lg]\n", arr[len-1]);
}

double find_max(double *arr, int len) {
    double max = arr[0];
    int i;
    for(i = 1; i < len; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int clear_array(double *arr, int len) {
    int left_arrow = 0, right_arrow = len-1, n = 0, i = 0;

    if (len == 1 && fabs(arr[0]) <= M_PI) n++;
    while(left_arrow != right_arrow) {
        if(fabs(arr[left_arrow]) <= M_PI) {
            n++;
            left_arrow++;
        } else {
            arr[left_arrow] = arr[right_arrow];
            arr[right_arrow] = 5;
            right_arrow--;
        }
    }
    if(fabs(arr[left_arrow]) <= M_PI) n++;

    return n;
}

int main() {
    int len;
    double arr[20], max;
    system("chcp 65001 > nul");

    len = input_len();
    fill_array(arr, len);
    show_array(arr, len);
    max = find_max(arr, len);
    printf("Максимальное число в массиве: %lg\n", max);

    len = clear_array(arr, len);
    show_array(arr, len);

    system("pause");
    return 0;
}