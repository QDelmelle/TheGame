#pragma once

#include <list>
#include "Shape.h"
#include "ofMain.h"

// an object that can throw other objects!
class Shooter:public Shape
{
public:
	Shooter(int, int, int);
	~Shooter();
	Shape *projectiles;	// list of the projectiles this shooter has launched.
	void shoot(int, int);	// shoot an object towards target coordinates and add it to projectiles.
	void update();
	void draw();
	bool shot;// à virer
	std::list<Shape> projectileList;
};
