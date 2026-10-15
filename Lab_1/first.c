#include <stdio.h>

int main() {
    double x, y;
    int is_defined = 0; // Прапорець: 0 - функція не визначена, 1 - визначена

    printf("Enter x: ");
    if (scanf("%lf", &x) == 1) {
        // Перевірка умов без використання && та ||
        if (x >= -49) {
            if (x < -10) {
                // x належить [-49, -10)
                y = 10 * x * x * x + (7.0 * x) / 5.0 + 2;
                is_defined = 1;
            } else if (x > 0) {
                if (x <= 10) {
                    // x належить (0, 10]
                    y = 10 * x * x * x + (7.0 * x) / 5.0 + 2;
                    is_defined = 1;
                } else if (x > 20) {
                    // x належить (20, +∞)
                    y = -x + 9;
                    is_defined = 1;
                }
            }
        }

        // Виведення результату
        if (is_defined == 1) {
            printf("y(x) = %.2lf\n", y);
        } else {
            printf("Function is not defined for x = %.2lf\n", x);
        }
    } else {
        printf("Invalid input. Please enter a number.\n");
    }

    return 0; // Єдина точка виходу з програми
}