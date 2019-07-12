#include "Missile.h"

Missile::Missile(int a, int b, int s, DataManager* dm) :Projectile(a, b, s, dm) {
	ExplodeImgNbr = 2;
	loadData(dm);

	//	effects
	effects[Utils::PHYSICAL] = 50;
	effects[Utils::BURN] = 5;
}
 
void Missile::loadData(DataManager* dm)
{
	// images
	texture = dm->textures[0];
	ExplodeAnimation.push_back(dm->textures[1]);
	ExplodeAnimation.push_back(dm->textures[2]);

	// sounds
	boom = dm->sounds[0];
	pup = dm->sounds[1];
}


