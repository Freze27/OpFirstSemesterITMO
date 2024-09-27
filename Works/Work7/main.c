#include <stdio.h>
#include <math.h>

enum Candy {
    Торт,
    Пирожное,
    Мороженое,
    Конфета,
};
struct point {
    int x;
    int y
};
void leinght(struct point start, struct point end) {
    int leinght = 0;
    leinght = sqrt(((end.x) - (start.x)) ^ 2 + ((end.y) - (start.y)) ^ 2);
    printf("%d\n", leinght);
}
struct status {
    unsigned int dsl: 1;
    unsigned int link: 1;
    unsigned int ppp : 1;
};
union ADSLModem {
    struct status flags;
    int value
};

int main() {
    union ADSLModem input;
    enum Candy x = Конфета;
    printf("%d\n", x);
    struct point start = {1, 2};
    struct point end = {65, 5};
    leinght(start, end);
    scanf("%x", &input.value);
    printf("%d\n", input.flags.dsl);
    printf("%d\n", input.flags.dsl);
    printf("%d\n", input.flags.dsl);
    return 0;
}
