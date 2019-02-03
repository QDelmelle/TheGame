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
	Shape::update();

	std::list<Shape>::iterator it;		//iterator
	for (it = projectileList.begin(); it != projectileList.end(); it++) //update all projectiles
	{
		it->update();
	}
}

void Shooter::draw()
{
	Shape::draw();
	ofDrawBitmapStringHighlight(std::to_string(projectileList.size()), 0, 15);
	std::list<Shape>::iterator it;
	for (it = projectileList.begin(); it != projectileList.end(); it++) //draw all projectiles
	{
		it->draw();
	}
	// draw each projectile
	//?
}