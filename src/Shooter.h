#pragma once

#include <vector>
#include "Shape.h"
#include "ofMain.h"

// an object that can throw other objects!
class Shooter:public Shape
{
public:
	Shooter(int, int, int);
	~Shooter();
	Shape *projectiles;	// list of the projectiles this shooter has launched.
	ofSoundPlayer  bang; //shooting sound
	ofSoundPlayer pup;	//disappearing sound

	virtual void shoot();	// shoot an object and add it to projectiles.
	virtual void update();
	void updateProjectiles();
	virtual void draw();
	void drawProjectiles();
	void checkCollision(Shape* target); //check for collisions between the shooter's
	//projectiles and target Shape.

	bool shot;// à virer
	std::vector<Shape*> projectileList;
};
