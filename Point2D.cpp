
#include "Point2D.h"


using namespace std;

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double yDist = p1.y - p2.y;
    double xDist = p1.x - p2.x;
    return sqrt(pow(xDist,2) + pow(yDist,2));
}
ostream& operator<<(ostream& left, const Point2D& p1) {
    left << "(" << p1.x <<", " << p1.y << ")";
    return left;
}
Point2D operator+(Point2D p1, Vector2D v2) {
    Point2D temp;
    temp.x = p1.x + v2.x;
    temp.y = p1.y + v2.y;
    return temp;
}
Vector2D operator-(Point2D p1, Point2D p2) {
    Vector2D temp;
    temp.x = p1.x - p2.x;
    temp.y = p1.y - p2.y;
    return temp;
}