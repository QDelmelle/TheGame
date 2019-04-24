#include "Knight.h"


Knight::Knight(int a, int b, int s, string name):Character(a, b, s, name)
{
	ofLoadImage(texture, "image/Knight.png");
	ofLoadImage(slashtexture, "image/KnightSlashing.png");
	health = 500;
}

Knight::~Knight()
{

}

void Knight::getHitBy(Projectile * p)
{
	health -= p->effects[Utils::PHYSICAL];
}
