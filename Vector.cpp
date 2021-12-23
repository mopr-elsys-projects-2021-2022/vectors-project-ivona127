#include "Vector.h"
#include <cmath>

Vector::Vector(): x(0), y(0) {}
Vector::Vector(double x, double y){
    this->x = x;
    this->y = y;
}
Vector::Vector(Point p1, Point p2){
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
}