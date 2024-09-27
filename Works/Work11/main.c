#include "geom.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    double args[10];
    for (int i = 0; i < 10; i++) {
        args[i] = atof(argv[i + 1]);
    }
    struct Polygon polygon = createPolygonFromArgs(args);
    double perimeter = calculatePerimeter(polygon);
    printf("Perimetr shape: %lf\n", perimeter);
    return 0;
}
