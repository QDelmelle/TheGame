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
	
	projectileList.push_back(*new Shape(x+2*size, y + 100*this->projectileList.size(), size / 4));
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