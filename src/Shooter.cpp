#include "Shooter.h"

Shooter::Shooter(int a, int b, int s):Shape(a,b,s)
{
	//?
}

Shooter::~Shooter()
{

}

void Shooter::shoot(int targetX, int targetY)
{
	//projectile = new Shape(x, y, int(size / 4), targetX, targetY, 20);
	//?
}

void Shooter::update() {
	//update each projectile
	//?
}

void Shooter::draw()
{
	Shape::draw();
	// draw each projectile
	//?
}