#pragma once
#include "Point.h"

class Vector {
	private:
		double x, y;
	public:
		Vector();
		Vector(double x, double y);
		Vector(Point p1, Point p2);
};

