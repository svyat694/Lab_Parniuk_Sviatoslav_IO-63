#include <stdio.h>

int main(void)
{
    int n;
    long long ops = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    double x = 1.0 / 3.0;
    ops += 2;
    double a = 2.0 * x;
    ops += 2;
    double sum = 0.0;
    ops += 1;
    double sign = 1.0;
    ops += 1;

    ops += 1;
    for (int i = 1; i <= n; i++) {
        ops += 2;
        int m = 2 * i;
        ops += 2;

        double t = 1.0;
        ops += 1;
        for (int j = 1; j <= m; j++) {
            ops += 2;
            t = t * a / j;
            ops += 3;
        }
        ops += 1;

        sum = sum + sign * t / 2.0;
        ops += 4;
        sign = -sign;
        ops += 2;
    }
    ops += 1;

    double S = 1.0 - sum;
    ops += 2;

    printf("S = %.7f\n", S);
    printf("Ops = %lld\n", ops);
    return 0;
}