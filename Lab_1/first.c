#include <stdio.h>
#include <windows.h> 

int main() {
  
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    float y = 0;
    float x = 0;

    printf("Введіть значення x: ");
    if (scanf("%f", &x) == 1) {
        if (x >= -49) {
            if (x < -10) {
               
                y = 10 * x * x * x + (7.0 * x) / 5.0 + 2;
                printf("y(x) = %.2f\n", y);
            } else {
                if (x > 0) {
                    if (x <= 10) {
                       
                        y = 10 * x * x * x + (7.0 * x) / 5.0 + 2;
                        printf("y(x) = %.2f\n", y);
                    } else {
                        if (x > 20) {
                           
                            y = -x + 9;
                            printf("y(x) = %.2f\n", y);
                        } else {
                           
                            printf("Функція не визначена для x = %.2f\n", x);
                        }
                    }
                } else {
                    
                    printf("Функція не визначена для x = %.2f\n", x);
                }
            }
        } else {
         
            printf("Функція не визначена для x = %.2f\n", x);
        }
    } else {
        printf("Помилка вводу!\n");
    }

    return 0;
}
