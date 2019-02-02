#include "Shape.h"
#include "ofMain.h"

// default methods for class Shape

Shape::Shape(int a, int b, int s)
{
	x = a;
	y = b;
	size = s;
	currentSize = s;
}


Shape::~Shape()
{
}

// green diamond
void Shape::draw() {
	ofFill();
	ofSetHexColor(0x45d326);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	ofVertex(x - size, y);
	ofVertex(x, y + size);
	ofVertex(x + size, y);
	ofVertex(x, y - size);
	ofEndShape();
}

// pulsating
void Shape::update() {
	currentSize = size*(1+sin(2* ofGetElapsedTimef()))/2;
}