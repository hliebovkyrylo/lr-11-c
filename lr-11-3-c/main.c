#include <stdio.h>
#include <math.h>
#include <windows.h>

double tanFunc(double x) {
    return tan(x);
}

double cos2xFunc(double x) {
    return cos(2 * x);
}

double diffFunc(double x, double (*f1)(double), double (*f2)(double)) {
    return f1(x) - f2(x);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a, b, h;

    printf("Введіть початкову точку інтервалу: ");
    while (scanf_s("%lf", &a) != 1) {
        printf("Помилка вводу. Введіть число: ");
        while (getchar() != '\n');
    }

    printf("Введіть кінцеву точку інтервалу: ");
    while (scanf_s("%lf", &b) != 1 || b < a) {
        printf("Помилка вводу. Кінцева точка має бути більшою за початкову: ");
        while (getchar() != '\n');
    }

    printf("Введіть крок: ");
    while (scanf_s("%lf", &h) != 1 || h <= 0) {
        printf("Помилка вводу. Крок має бути більшим за нуль: ");
        while (getchar() != '\n');
    }

    printf("    x    |   tan(x)   |   cos(2x)   |   Різниця\n");
    printf("---------------------------------------------------\n");

    for (double x = a; x <= b; x += h) {
        double tanVal = tanFunc(x);
        double cos2xVal = cos2xFunc(x);
        double diff = diffFunc(x, tanFunc, cos2xFunc);
        printf("%8.4f | %10.6f | %10.6f  | %10.6f\n", x, tanVal, cos2xVal, diff);
    }

    return 0;
}
