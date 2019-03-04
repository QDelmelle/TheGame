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
	vector<int> effectsDodged;

	//override Shape
	virtual void draw();
	virtual void getHitBy(Projectile * p);

	// check espace entre bodies

};

