#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Введите число: ");
    
    // Проверяем, что введено именно число
    if (scanf("%d", &num) != 1) {
        return 3; // Код ошибки ввода
    }

    if (num > 0) return 1;      // Положительное
    else if (num < 0) return 2; // Отрицательное
    else return 0;              // Равно нулю
}
