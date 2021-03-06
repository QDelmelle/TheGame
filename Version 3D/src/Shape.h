#pragma once

#include "ofMain.h" //to access ofVec2f

// shape: any drawable moving or static object must implement this.
class Shape
{
public:
	Shape(int, int, int);
	~Shape();

	int x, y, size;		// position of the center and default size of the object.
	int currentSize; // actual size of the object at the moment.
	ofVec2f speedVector;
	bool isMoving;
	float refTime; // elapsed time since last update
	ofSpherePrimitive head;

	virtual void update(); // update size, position, etc to make it evolve.
	virtual void draw(); // draw function, called on each frame.
	virtual void move(ofVec2f); //move the shape, to stop call move(ofVec2f(0,0))
	virtual void stop(); //obvious
	bool isOutTheWindow();
};
