#include "Knight.h"


Knight::Knight(int a, int b, int s, string name):Character(a, b, s, name)
{
	ofLoadImage(texture, "image/Knight.png");
	health = 500;
}

Knight::~Knight()
{
}

void Knight::getHitBy(Projectile * p)
{
	//take dmg and effects
}
