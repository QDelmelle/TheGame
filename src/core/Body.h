#pragma once
#include "Shape.h"
#include "Projectile.h"


class Projectile;

class Body : public Shape
{
public:
	Body(int a, int b, int s);
	~Body();

	int health;
	ofTexture texture;
	std::vector<ofTexture> burningAnimation;

	// Body only
	int burnTicks; // number of ticks the body has to take while burning
	int burnDmg;	// burning Damage the bidy takes at each tick.
	float burnTime; // number of s. since the last tick of burning (1 tick= 1/2 s)
	
	//override Shape
	virtual void draw();
	virtual void getHitBy(Projectile * p)=0;
	virtual void update();

	// check espace entre bodies

};

