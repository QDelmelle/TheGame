
#pragma once

#include "Body.h"
#include "Shape.h"


class Projectile :public Shape {
public:
	Projectile(int, int, int);
	~Projectile();

	ofTexture texture;
	ofVec2f sommets[4];
	int angle;			// orientation par rapport à (1,0)

	virtual void affect(Body * target);		// affect target by exploding in its face
	virtual bool checkCollision(Shape * target); // check if this projectile's and the 
	//target's hitboxes are colliding.

	// overrides Shape
	virtual void draw();
	virtual void move(ofVec2f);

};