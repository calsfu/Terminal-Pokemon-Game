#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"

#include <ostream>
using namespace std;

int main() {
    Point2D p1;
    Point2D p2 = Point2D(5, 3);
    Vector2D v1;
    Vector2D v2 = Vector2D(3,2);
    Point2D p3 = p1 + v2;
    Vector2D v3 = p1 - p2;
    cout << p1 << p2 << p3 << endl;
    cout << (v3) << endl;

   
}