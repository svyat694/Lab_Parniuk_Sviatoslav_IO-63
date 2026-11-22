#include <stdio.h>

int main(void)
{
    int n;
    long long ops = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    double x = 1.0 / 3.0;
    ops += 2;
    double c = 4.0 * x * x;
    ops += 3;
    double term = x * x;
    ops += 2;
    double sum = 0.0;
    ops += 1;

    ops += 1;
    for (int i = 1; i <= n; i++) {
        ops += 2;
        sum = sum + term;
        ops += 2;
        term = -term * c / ((2.0 * i + 1.0) * (2.0 * i + 2.0));
        ops += 10;
    }
    ops += 1;

    double S = 1.0 - sum;
    ops += 2;

    printf("S = %.7f\n", S);
    printf("Ops = %lld\n", ops);
    return 0;
}