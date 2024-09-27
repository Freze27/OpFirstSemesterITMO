#include <stdio.h>


int main() {
    int number, number_1;
    scanf("%d", &number);
    int answer = (number >= 20) && (number <= 30);
    printf("%d\n", answer);
    scanf("%d", &number_1);
    printf("%d", (number_1 >> 16) & 1);
    return 0;
}
