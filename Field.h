#pragma once

#include "Ball.h"
#include "Line.cpp"

class Field {
	Ball ball;
	Point startingPoint;
	Point endPoints[4];

public:
	Field();
	Field(Point origin, double width, double height, Ball ball);
	Field(Point endPoints[4], Ball ball);
	int Place(Point p, Line AB, Line BC, Line CD, Line DA);
	int inTheCorner(Point p);
	void hit(Point target, double power);

	friend ostream& operator<<(ostream& os, const Field& f);
	friend void ballCase(Field& f);

};

void simpleCase(Field& f);
void complexCase(Field& f);
void ballCase(Field& f);
