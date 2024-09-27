#include "geom.h"
#include <stdio.h>
#include <math.h>

double calculatePerimeter(struct Polygon polygon) {
    double dx = polygon.dot[0].x - polygon.dot[1].x;
    double dy = polygon.dot[0].y - polygon.dot[1].y;
    double perimeter = 5*sqrt(dx * dx + dy * dy);
    return perimeter;
}

struct Polygon createPolygonFromArgs(double args[]) {
    struct Polygon polygon;
    for (int i = 0; i < 5; i++) {
        polygon.dot[i].x = args[2 * i];
        polygon.dot[i].y = args[2 * i + 1];
    }
    return polygon;
}