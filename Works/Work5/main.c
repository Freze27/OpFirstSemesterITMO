#include <stdio.h>

int main() {
    int size_mass = 7;
    int mass[] = {90, 76, 54, 23, 56, 12, 48};
    for (int i = 0; i < size_mass; i++) {
        printf("%d ", i);
        printf("%d\n", mass[i]);
    }
    int size_m = 2;
    int result = 0;
    int m1[2][2] = {1, 2, 3, 4};
    int m2[2][2] = {1, 0, 0, 1};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result = 0;
            for (int k = 0; k < 2; k++) {
                result += m1[i][k] * m2[k][j];
            }
            printf("%d ", result);
            if (j == size_m - 1) {
                printf("\n");
            }
        }
    }
}
