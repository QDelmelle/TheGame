#include "Shape.h"
#include "ofMain.h"

// default methods for class Shape

Shape::Shape(int a, int b, int s)
{
	x = a;
	y = b;
	size = s;
	currentSize = s;
	speedVector = ofVec2f(0, 0);
	isMoving = false;
	head.set(s, 100); //set(radius, resolution, primitiveMode)
	head.setPosition(x, y, 0);
	head.rotateDeg(180, 0, 1, 0);
}


Shape::~Shape()
{
}

// green diamond
void Shape::draw() {
	
	head.draw();

	ofDrawBitmapStringHighlight("isMoving = " + std::to_string(isMoving), 10, 45);
}


void Shape::update() {
	currentSize = size*(1+0.24*sin(3* ofGetElapsedTimef())/2); // pulsating
	if (isMoving) {
		float t = ofGetElapsedTimef() - refTime;
		x = x + t * speedVector.x;
		y = y + t * speedVector.y;
		refTime = ofGetElapsedTimef();
	}
	head.setPosition(x,y,0); //the sphere
}

void Shape::move(ofVec2f v) // v = direction and velocity (not a target)
{
	speedVector = v;
	isMoving = true;
	refTime = ofGetElapsedTimef();
}

void Shape::stop()
{
	isMoving = false;
}

bool Shape::isOutTheWindow()
{
	return (x < -size || y < -size || x > ofGetWidth() + size || y > ofGetHeight() + size);
}