#ifndef GEOM_H
#define GEOM_H
struct Point {
    double x;
    double y;
};
struct Polygon {
    struct Point dot[5];
};
double calculatePerimeter(struct Polygon polygon);
struct Polygon createPolygonFromArgs(double args[]);
#endif