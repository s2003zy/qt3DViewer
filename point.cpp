#include "point.h"

double Point::distant(const Point& p) {
    return sqrt(pow( p.x - this -> x, 2.0) +
                pow( p.y - this -> y, 2.0) +
                pow( p.z - this -> z, 2.0));
}
