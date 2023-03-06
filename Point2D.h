#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"
#include <string.h>
#include <sstream>
#include <math.h>
#include "Vector2D.h"
class Point2D {
    public:
    double x;
    double y;
    Point2D() {
        x = 0;
        y = 0;
    }
    Point2D(double in_x, double in_y) {
        x = in_x;
        y = in_y;
    }
    
};
double GetDistanceBetween(Point2D, Point2D);
Point2D operator+(Point2D, Vector2D);
Vector2D operator-(Point2D , Point2D );
std::ostream& operator<<(std::ostream& left, const Point2D& p1);
#endif