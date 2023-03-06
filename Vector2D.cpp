#include <iostream>
#include "Vector2D.h"
using namespace std;

Vector2D operator*(Vector2D v1, double d) {
    Vector2D temp;
    temp.x = v1.x * d;
    temp.y = v1.y * d;
    return temp;
}

Vector2D operator/(Vector2D v1, double d) {
    Vector2D temp;
    temp.x = v1.x / d;
    temp.y = v1.y / d;
    return temp;
}

ostream& operator<<(ostream& left, Vector2D& v1) {
    left << "<" << v1.x <<", " << v1.y << ">";
    return left;
}