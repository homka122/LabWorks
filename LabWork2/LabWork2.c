#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_znak(double x[5], double y[5]);
int count_paral_line(double x[5], double y[5]);
int count_equ_line(double x[5], double y[5]);
int find_is_equ_diag(double x[5], double y[5]);

int main() {
    int is_equ_diag = 0, equ_line = 0, paral_line = 0, vipuc = 0;
    double x[5];
    double y[5];

    system("chcp 1251 > null");

    printf("Введите координаты 4-ех точек\n");

    printf("Первая точка: ");
    scanf("%lf%lf", &x[1], &y[1]);

    printf("Вторая точка: ");
    scanf("%lf%lf", &x[2], &y[2]);

    printf("Третья точка: ");
    scanf("%lf%lf", &x[3], &y[3]);

    printf("Четвертая точка: ");
    scanf("%lf%lf", &x[4], &y[4]);

    vipuc = abs(find_znak(x, y)) == 4 ? 1 : 0; // Если колличество элементов с одним знаком равно 4, то фигура выпуклая
    paral_line = count_paral_line(x, y);
    equ_line = count_equ_line(x, y);
    is_equ_diag = find_is_equ_diag(x, y);

    if (vipuc == 1) {
    	if (paral_line == 2) {
    		if(is_equ_diag) {
    			if (equ_line == 2) {
    				printf("Квадрат");
				} else if (equ_line == 1) {
					printf("Прямоугольник");
				}
			} else {
				if (equ_line == 1) {
					printf("Параллелограмм");
				} else {
					printf("Произвольная фигура"); // Вообще - ромб
				}
			}
		} else if (paral_line == 1) {
			printf("Трапеция");
		} else {
			printf("Произвольная фигура");
		}
	} else {
		printf("Проивольная фигура");
	}

	printf("\n");
	system("pause");
	return 0;

}

//Определение выпуклости фигуры с помощью произведения векторов (против часовой)
int find_znak(double x[5], double y[5]) {
    int znak = 0;
    double x1_t, x2_t, y1_t, y2_t;

	// [x1_t;y1_t] - AB
	// [x2_t;y2_t] - BC
    x1_t = x[2] - x[1];
    y1_t = y[2] - y[1];
    x2_t = x[3] - x[2];
    y2_t = y[3] - y[2];
    znak += x1_t * y2_t - x2_t * y1_t > 0 ? 1 : -1; // [ABxBC]

    x1_t = x[3] - x[2];
    y1_t = y[3] - y[2];
    x2_t = x[4] - x[3];
    y2_t = y[4] - y[3];
    znak += x1_t * y2_t - x2_t * y1_t > 0 ? 1 : -1;

    x1_t = x[4] - x[3];
    y1_t = y[4] - y[3];
    x2_t = x[1] - x[4];
    y2_t = y[1] - y[4];
    znak += x1_t * y2_t - x2_t * y1_t > 0 ? 1 : -1;

    x1_t = x[1] - x[4];
    y1_t = y[1] - y[4];
    x2_t = x[2] - x[1];
    y2_t = y[2] - y[1];
    znak += x1_t * y2_t - x2_t * y1_t > 0 ? 1 : -1;


	// Если все значения разности имели один знак, значит фигура выпуклая, а znak по модулю имеет число 4 - кол-во элементов с одним элементом
    return znak;
}

// Поиск количества пар параллельных сторон
int count_paral_line(double x[5], double y[5]) {

    int paral_line = 0;

	// Если соотношеие разности Х и Y координаты начальной и конечной точки стороны равны аналогичному соотношению другой стороны
	// то стороны параллельны
	// Если разность Икса\Игрека точки начала отрезка и Икса\Игрека конечной точки отрезка равна нулю
	// И если у второго отрезка аналогично разность равна нулю - то эти две стороны параллельны
    if (x[2] - x[1] != 0 && y[2] - y[1] != 0 && x[4] - x[3] != 0 && y[4] - y[3] != 0) {
        if ((x[2] - x[1]) / (y[2] - y[1]) == (x[4] - x[3]) / (y[4] - y[3])) {
            paral_line++;
        }
    } else if ((x[2] - x[1] == x[4] - x[3] && x[2] - x[1] == 0) || (y[2] - y[1] == y[4] - y[3] && y[2] - y[1] == 0)) {
        paral_line++;
    }

    if (x[3] - x[2] != 0 && y[3] - y[2] != 0 && x[1] - x[4] != 0 && y[1] - y[4] != 0) {
        if ((x[3] - x[2]) / (y[3] - y[2]) == (x[1] - x[4]) / (y[1] - y[4])) {
            paral_line++;
        }
    } else if ((x[3] - x[2] == x[1] - x[4] && x[3] - x[2] == 0) || (y[3] - y[2] == y[1] - y[4] && y[3] - y[2] == 0)) {
        paral_line++;
    }

    return paral_line;
}

// Определения свойства равности строк
// 2 - все строки равны
// 1 - противолежащие строки равны
// 0 - Остальные случаи
int count_equ_line(double x[5], double y[5]) {
	int equ_line = 0;
	double p[5];

	//длины сторон
	p[1] = pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2);
	p[2] = pow(x[2] - x[3], 2) + pow(y[2] - y[3], 2);
	p[3] = pow(x[3] - x[4], 2) + pow(y[3] - y[4], 2);
	p[4] = pow(x[4] - x[1], 2) + pow(y[4] - y[1], 2);

	if (p[1] == p[2] && p[2] == p[3] && p[3] == p[4] && p[4] == p[1]) {
		equ_line = 2;
	} else if (p[1] == p[3] && p[2] == p[4]) {
		equ_line = 1;
	}

	return equ_line;
}

//Являются ли диагонали равными
int find_is_equ_diag(double x[5], double y[5]) {
	int is_equ_diag = 0, diag1 = 0, diag2 = 0;

	//Длины диагоналей
	diag1 = pow(x[1] - x[3], 2) + pow(y[1] - y[3], 2);
	diag2 = pow(x[2] - x[4], 2) + pow(y[2] - y[4], 2);

	if (diag1 == diag2) {
		is_equ_diag = 1;
	}

	return is_equ_diag;
}
