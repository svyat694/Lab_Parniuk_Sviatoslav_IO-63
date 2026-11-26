#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define LOW  0.0
#define HIGH 5.0

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int n, i, j;
    double A[10][10];

    printf("Введіть розмір матриці n (7..10): ");
    if (scanf("%d", &n) != 1 || n < 7 || n > 10) {
        printf("Некоректний розмір.\n");
        return 1;
    }

    printf("Введіть елементи матриці (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%lf", &A[i][j]) != 1) {
                printf("Помилка введення.\n");
                return 1;
            }

    printf("\nМатриця :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%8.2f", A[i][j]);
        printf("\n");
    }

        printf("\nПобічна діагональ: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", A[n - 1 - i][i]);
    printf("\n");

       for (i = 0; i + 1 < n; i++)
        if (A[n - 1 - i][i] < A[n - 2 - i][i + 1]) {
            printf("Діагональ НЕ впорядкована за незбільшенням!\n");
            return 1;
        }

        int lo = 0, hi = n - 1, mid, steps = 0, found = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        steps++;
        double x = A[n - 1 - mid][mid];
        printf("Крок %d: low=%d high=%d middle=%d, елемент = %.2f\n",
               steps, lo, hi, mid, x);
        if (x > HIGH)
            lo = mid + 1;
        else if (x < LOW)
            hi = mid - 1;
        else {
            found = 1;
            break;
        }
    }

    if (found)
        printf("\nЕлемент %.2f з діапазону [0,5] : рядок %d, стовпець %d "
               "; індекси [%d][%d]\n",
               A[n - 1 - mid][mid], n - mid, mid + 1, n - 1 - mid, mid);
    else
        printf("\nУ побічній діагоналі немає елементів з діапазону [0,5].\n");

    printf("Кроків двійкового пошуку: %d; у лінійному пошуку було б до %d.\n",
           steps, n);
    return 0;
}