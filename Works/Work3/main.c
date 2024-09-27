#include <stdio.h>

int main() {
    int number;
    int number5;
    scanf("%d", &number);
    printf("2) ");
    printf("%o \n", number);
    printf("3) ");
    printf("%o ", number);
    printf("%o\n", number << 1);
    printf("4) ");
    printf("%o\n", ~number);
    scanf("%o", &number5);
    printf("5) ");
    printf("%o",number5 ^ number);
    return 0;
}
