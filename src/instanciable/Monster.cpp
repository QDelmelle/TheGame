
#include "Monster.h"


Monster::Monster(int a, int b, int s):Character(a, b, s, "Bouboule") //a = pos x, b = pos y, s = size, hp = health points
{
	ofLoadImage(texture, "image/Phantom.png");
}

Monster::~Monster()
{

}

void Monster::getHitBy(Projectile * other)
{
	Body::getHitBy(other);
	if (health <= 0) isAlive = false;
}

void Monster::move(ofVec2f v)
{
	Shape::move(v);
}

void Monster::draw()
{
	if (isAlive) {
		Character::draw();
		ofDrawBitmapStringHighlight(std::to_string(health), x + 30, y + 30);
	}
}

void Monster::update()
{
	if(isAlive)
		Character::update();
}
