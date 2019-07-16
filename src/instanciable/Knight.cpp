#include "Knight.h"


Knight::Knight(int a, int b, int s, DataManager* dm, string name):Character(a, b, s, dm, name)
{
	health = 500;
	deathAnimTicks = 0;
	loadData(dm);
}

Knight::~Knight()
{

}

void Knight::slash()
{
}

void Knight::getHitBy(Projectile * p)
{
	health -= p->effects[Utils::PHYSICAL];
	if (health <= 0) {
		health = 500; // triche totale :p
		printf("mdr jui immortel\n");
	}
}

void Knight::loadData(DataManager * dm)
{
	//load textures
	texture = dm->textures[28];
	slashtexture = dm->textures[29];

	//load sounds
}
