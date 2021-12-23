#include "Field.h"

Field::Field() {}

Field::Field(Point origin, double width, double height, Ball ball) {
	endPoints[0] = Point(origin.x, origin.y);
	endPoints[1] = Point(origin.x + width, origin.y);
	endPoints[2] = Point(origin.x + width, origin.y + height);
	endPoints[3] = Point(origin.x, origin.y + height);

	this->ball = ball;
	this->startingPoint = ball.center;
}

Field::Field(Point endPoints[4], Ball ball) {
	for (int i = 0; i < 4; ++i) {
		this->endPoints[i] = endPoints[i];
	}

	this->ball = ball;
	this->startingPoint = ball.center;
}

int Field::Place(Point p, Line AB, Line BC, Line CD, Line DA){
	// If the equation has a negative solution, it means that the ball is out of bounds.
	
	int place = 0; // in the field 

    if((AB.A*p.x + AB.B*p.y + AB.C) < 0){
        place = 1; // outside AB
    }
        
	if((BC.A*p.x + BC.B*p.y + BC.C) < 0){
        place = 2; // outside BC
    }

    if((CD.A*p.x + CD.B*p.y + CD.C) < 0){
        place = 3; // outside CD
    }
        
	if((DA.A*p.x + DA.B*p.y + DA.C) < 0){
        place = 4; // outside DA
    }
    
	return place;
}

int Field::inTheCorner(Point p){
	int IsintheCorner = 0; // not in the corner
	for(int i = 0; i < 4; i++){ 
		if(p.x == endPoints[i].x && p.y == endPoints[i].y){
			IsintheCorner = i+1; // save the corner
		}
	}
	return IsintheCorner;
}

void Field::hit(Point target, double power) {
	if(power < 1 || power > 10){
        cout << "The power must be in" << endl;
    }
    
	if (ball.diameter < 0 ){
        cout << "The diameter must not be less than 0"<< endl;
    }

	Point endPointsWithBallRadius[4];
    double radius = ball.diameter/2;
    
	// Shortening the field with the radius of the ball
	endPointsWithBallRadius[0] = Point(endPoints[0].x + radius, endPoints[0].y + radius);
    endPointsWithBallRadius[1] = Point(endPoints[1].x - radius, endPoints[1].y + radius);
    endPointsWithBallRadius[2] = Point(endPoints[2].x - radius, endPoints[2].y - radius);
    endPointsWithBallRadius[3] = Point(endPoints[3].x + radius, endPoints[3].y - radius);
	
	// create the line of the field without the radius of the ball
    Line AB(endPointsWithBallRadius[0], endPointsWithBallRadius[1]);
    Line BC(endPointsWithBallRadius[1], endPointsWithBallRadius[2]);
    Line CD(endPointsWithBallRadius[2], endPointsWithBallRadius[3]);
    Line DA(endPointsWithBallRadius[3], endPointsWithBallRadius[0]);

	if(Place(startingPoint, AB, BC, CD, DA) !=0 ){
        cout << "Wrong strating point."<< endl;
    }

	if(inTheCorner(startingPoint)!=0){
        cout << "The starting point is in the corner."<< endl;
    }

	Point FinalPoint;
	FinalPoint.x = startingPoint.x + ( (target.x-startingPoint.x) *power);
	FinalPoint.y = startingPoint.y + ( (target.y-startingPoint.y) *power);

}
ostream& operator<<(ostream& os, const Field& f) {
	os << "Field points:" << endl;
	for(int i = 0; i < 4; i++)
		os << "  " << f.endPoints[i] << endl;
	os << f.ball;

	return os;
}

void simpleCase(Field& f) {
	Point origin;
	double width, height;
	Ball ball;
	cout << "Point of origin of field: ";
	cin >> origin;
	cout << "Width and height of field: ";
	cin >> width >> height;
	cin >> ball;
	f = Field(origin, width, height, ball);	
}

void complexCase(Field& f) {
	Point endPoints[4];
	Ball ball;
	cout << "Field points: " << endl;
	for (int i = 0; i < 4; ++i) {
		cout << "  " << i+1 << ") ";
		cin >> endPoints[i];
	}
	cin >> ball;
	f = Field(endPoints, ball);
}

void ballCase(Field& f) {
	Ball ball;
	cin >> ball;
	f = Field(f.endPoints, ball);
}