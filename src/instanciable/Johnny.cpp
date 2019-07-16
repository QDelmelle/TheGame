
#include "Johnny.h"


Johnny::Johnny(int a, int b, int s, DataManager* dm):Shooter(a, b, s, dm, "Johnny") //a = pos x, b = pos y, s = size, hp = health points
{
	health = 100;
	roundsLeft = 0;
	rps = 1;
	shotTime = 0;
	loadData(dm);
}

Johnny::~Johnny()
{

}


void Johnny::loadData(DataManager* dm)
{
	texture = dm->textures[3];
	shootingTexture = dm->textures[4];
	bang = dm->sounds[2];
}

void Johnny::update()
{
	if (roundsLeft > 0 && ofGetElapsedTimef()-shotTime > 1/rps) {
		shoot();
		shotTime = ofGetElapsedTimef();
		roundsLeft--;
	}
	Shooter::update();
}

void Johnny::canarder(int mun, float rps)
{
	roundsLeft = mun;
	this->rps = rps;
}

void Johnny::shoot()
{
	Missile* m = new Missile(x, y, size / 4, dm);
	Shooter::shoot(m);
}

void Johnny::draw()
{
	Shooter::draw();
}

void Johnny::getHitBy(Projectile * p)
{
	health -= p->effects[Utils::PHYSICAL];
	burnDmg = max(burnDmg, p->effects[Utils::BURN]);
	burnTicks = 10;
	burnTime = ofGetElapsedTimef();
}

