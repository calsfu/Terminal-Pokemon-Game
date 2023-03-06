#ifndef VECTOR2D_H
#define VECTOR2D_H
class Vector2D {
    public:
    double x;
    double y;
    Vector2D() {
        x = 0.0;
        y = 0.0;
    }
    Vector2D(double in_x, double in_y) {
        x = in_x;
        y = in_y;
    }
};

Vector2D operator*(Vector2D v1, double d);
Vector2D operator/(Vector2D v1, double d);
std::ostream& operator<<(std::ostream& left, Vector2D& v1);

#endif