#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

void matrix_create(struct point mass[], int n) {
    float matrix[n][n - 1];
    float distance;
    for (int i = 0; i < n; i++) {
        struct point memory;
        memory = mass[i];
        mass[i] = mass[0];
        mass[0] = memory;
        for (int j = 1; j < n; j++) {
            distance = sqrtf(powf((mass[0].x - mass[j].x), 2) +
                             powf((mass[0].y - mass[j].y), 2));
            matrix[i][j - 1] = distance;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", matrix[i][j]);
            if (j == n - 2) {
                printf("\n");
            }
        }
    }
}

int sum(int number) {
    if (number == 0) {
        return 0;
    } else {
        return number % 10 + sum(number / 10);
    }
}


int main() {
    int n, x, y;
    scanf("%d", &n);
    struct point mass[n];
    struct point point_n;
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x, &y);
        point_n.x = x;
        point_n.y = y;
        mass[i] = point_n;
    }
    matrix_create(mass, n);
    int number;
    scanf("%d", &number);
    printf("%d", sum(number));
    return 0;
}
