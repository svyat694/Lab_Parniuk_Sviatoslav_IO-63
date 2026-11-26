#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define M 8
#define N 9
#define START 1

void bubbleSortFlag(int a[M][N])
{
    int k = (N - START + 1) / 2;
    int flag = 1;

    for (int pass = 1; pass < k && flag; pass++) {
        flag = 0;
        for (int t = 0; t < k - pass; t++) {
            int j = START + 2 * t;
            if (a[0][j] > a[0][j + 2]) {
                int tmp = a[0][j];
                a[0][j] = a[0][j + 2];
                a[0][j + 2] = tmp;
                flag = 1;
            }
        }
    }
}

void printMatrix(int a[M][N])
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int a[M][N];

       int row0[N] = { 1, 5, 12, -2, 0, 7, 8, 7, 2 };

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = (i == 0) ? row0[j] : i * 10 + j;

    printf("Вихідна матриця:\n");
    printMatrix(a);

    bubbleSortFlag(a);

    printf("\nПісля сортування:\n");
    printMatrix(a);

    return 0;
}