#ifndef POINT_H
#define POINT_H

#include <cmath>
class Point
{
public:
    double x, y ,z;
    Point(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
    Point(double *vec) {
        x = vec[0];
        y = vec[1];
        z = vec[2];
    }
    Point(const Point&p) : x(p.x), y(p.y), z(p.z) {}
    double distant(const Point& p);
    Point() : x(0), y(0), z(0) {}
    Point operator + (const Point &a) const {
        Point res(this -> x + a.x, this -> y + a.y, this -> z + a.z);
        return res;
    }
    Point operator - (const Point &a) const {
        Point res(this -> x - a.x, this -> y - a.y, this -> z - a.z);
        return res;
    }
    double operator *(const Point &a) const {
        double res = this -> x * a.x +  this -> y * a.y + this -> z * a.z;
        return res;
    }
    Point operator *(double k) const {
        Point res(this -> x * k, this -> y * k, this -> z * k);
        return res;
    }
    Point operator /(double k) const {
        if (fabs(k) > 1e-8) {
            Point res(this -> x / k, this -> y / k, this -> z / k);
            return res;
        }
        return *this;
    }

    double len() {
        double res = sqrt((x * x) + (y * y) + (z * z));
        return res;
    }

};

#endif // POINT_H
