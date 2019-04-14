
#pragma once

#include "Body.h"

class Body;

class Projectile :public Shape 
{
public:
	Projectile(int, int, int);
	~Projectile();

	ofTexture texture;
	ofVec2f sommets[4];

	// unique
	int angle;			// orientation par rapport à (1,0)
	int effects[20];	// puissance par effet

	ofSoundPlayer boom;	//exploding sound
	ofSoundPlayer pup;	//disappearing sound

	int ExplodeTicks;
	int ExplodeImgNbr;
	std::vector<ofTexture> ExplodeAnimation;
	virtual void Explode( int );

	virtual bool checkCollision(Body * target); // check if this projectile's and the 
	//target's hitboxes are colliding.

	// overrides Shape
	virtual void draw();
	virtual void update();
	virtual void move(ofVec2f);
};