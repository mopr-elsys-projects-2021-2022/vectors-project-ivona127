#include "Line.h"

Line::Line(Point& p1, Point& p2){
    A = p1.y - p2.y;
    B = p2.x - p1.x;       
    C = -(A*p1.x + B*p1.y);
}

Line::Line(double A, double B){
    this->A = -B;
    this->B = A;
    C = 0;
}
