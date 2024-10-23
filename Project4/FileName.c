#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double f1(double);
double f2(double);
double sin_n(double, int);
double sin_eps(double, double);
int triangle(int);

int main() {
	double x, eps;
	int N;
	setlocale(LC_CTYPE, "RUS");
	
	printf("Введите x\n");
	scanf("%lf", &x);
	getchar();
	printf("F1(x) = %lf\nF2(x) = %lf\nF1(x)*F2(x) = %lf\nF1(x)^2 - F2(x)^2 = %lf\n2*(F1(x)+F2(x)) = %lf\n", f1(x), f2(x), f1(x)*f2(x), pow(f1(x), 2) - pow(f2(x), 2), 2*(f1(x) + f2(x)));
	
	printf("Введите угол (в радианах)\n");
	scanf("%lf", &x);
	getchar();
	printf("sin(%d) = %lf\n", (int)x, sin(x));
	
	printf("Введите угол (в радианах) и количество суммируемых k-x членов ряда\n");
	scanf("%lf %ld", &x, &N);
	getchar();
	printf("Членов ряда - %d\nsin(%d) = %lf\n", N, (int)x, sin_n(x, N));
	
	printf("Введите угол(в радианах) и погрешность\n");
	scanf("%lf %lf", &x, &eps);
	getchar();
	printf("Погрешность - %lf\nsin(%d) = %lf\n", eps, (int)x, sin_eps(x, eps));

	printf("Введите радиус\n");
	scanf("%d", &(int)x);
	getchar();
	triangle(x);
}

double f1(double x) {
	double y;
	y = x <= 3 ? pow(x, 2) - 3 * x + 9 : 1 / (pow(x, 3) + 3);
	return y;
}

double f2(double x) {
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}

double sin_n(double x, int N) {
	double prev = x;
	double sm = x;
	int k = 1;
	while (k <= N) {
		prev *= -pow(x, 2) / ((2 * k) * (2 * k + 1));
		sm += prev;
		k++;
	}
}

double sin_eps(double x, double eps) {
	double sm = x; // Начальное значение для синуса
	double prev_sm = x;   // Первый член ряда
	int k = 1;         // Индекс для ряда


	while (fabs(prev_sm) > eps) {
		prev_sm *= -pow(x, 2) / ((2 * k) * (2 * k + 1)); // Формула для следующего члена ряда
		sm += prev_sm;
		k++;
	}
	return sm; // Возвращаем результат
}

int triangle(int x) {
	char a = '.';
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < i; j++) {
			printf("%c", a);
		}
		printf("\n");
	}
}