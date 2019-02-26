#pragma once
#include "Shape.h"
class Projectile;

class Body : public Shape
{
public:
	Body(int a, int b, int s);
	~Body();

	int health;
	ofTexture texture;
	//override Shape
	virtual void draw();
	virtual void getHitBy(Projectile * p);
};

