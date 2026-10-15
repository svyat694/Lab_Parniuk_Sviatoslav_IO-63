#include <stdio.h>
#include <windows.h>

int main() {
    // Налаштування кодування UTF-8 для коректного виводу українських літер
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x = 0;
    double y = 0;

    printf("Введіть значення x: ");
    if (scanf("%lf", &x) == 1) {

        // Перевірка D1: x належить [-49, -10) АБО (0, 10]
        if ((x >= -49 && x < -10) || (x > 0 && x <= 10)) {
            y = 10 * x * x * x + (7.0 * x) / 5.0 + 2;
            printf("y(x) = %.2lf\n", y);
        }
        // Перевірка D2: x належить (20, +∞)
        else if (x > 20) {
            y = -x + 9;
            printf("y(x) = %.2lf\n", y);
        }
        // Якщо x не потрапив у жоден з проміжків
        else {
            printf("Функція не визначена для x = %.2lf\n", x);
        }

    } else {
        printf("Помилка вводу!\n");
    }

    return 0; // Єдина точка виходу
}
