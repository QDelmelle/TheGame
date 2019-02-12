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
}


Shape::~Shape()
{
}

// green diamond
void Shape::draw() {
	
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	ofSetHexColor(0x45d326);
	ofFill();
	ofVertex(x - currentSize, y);
	ofVertex(x, y + currentSize);
	ofVertex(x + currentSize, y);
	ofVertex(x, y - currentSize);
	ofEndShape();

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

void Shape::explode(Shape * target)
{
	// make target suffer here
}

bool Shape::checkCollision(Shape * target)
{
	return (pow(x-target->x, 2)+ pow(y - target->y, 2) < pow(size + target->size, 2)); // fancy math in there
}

bool Shape::isOutTheWindow()
{
	return (x < -size || y < -size || x > ofGetWidth() + size || y > ofGetHeight() + size);
}