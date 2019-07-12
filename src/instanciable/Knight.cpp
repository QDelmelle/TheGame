#include "Knight.h"


Knight::Knight(int a, int b, int s, DataManager* dm, string name):Character(a, b, s, dm, name)
{
	health = 500;
	loadData(dm);
}

Knight::~Knight()
{

}

void Knight::getHitBy(Projectile * p)
{
	health -= p->effects[Utils::PHYSICAL];
}

void Knight::loadData(DataManager * dm)
{
	//load textures
	texture = dm->textures[28];
	slashtexture = dm->textures[29];

	//load sounds
}
