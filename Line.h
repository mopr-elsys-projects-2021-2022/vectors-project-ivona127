#pragma once
#include "Point.h"

class Line {
	public:
		double A, B, C;
		Line(Point& p1, Point& p2);
		Line(double A, double B);
};

