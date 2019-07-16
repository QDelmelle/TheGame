#include "Shooter.h"

Shooter::Shooter(int a, int b, int s, DataManager* dm, string name):Character(a,b,s, dm, name)
{
	// load sounds
	
}

Shooter::~Shooter()
{

}

void Shooter::shoot(Projectile *projectile)
{
	projectile->move(ofVec2f(ofGetMouseX() - x, ofGetMouseY() - y));
	projectileList.push_back(projectile);
	bang.play();
	shotTime = ofGetElapsedTimef();
}

void Shooter::update() {
	Character::update();
	updateProjectiles();
}

void Shooter::draw()
{
	drawProjectiles();

	if (projectileList.size() > 0 and ofGetElapsedTimef() - shotTime < .3) {
		shootingTexture.draw(ofPoint(x - currentSize, y - currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x - currentSize, y + currentSize));
	}
	else
		Character::draw();
}

//update all projectiles
void Shooter::updateProjectiles() {

	unsigned int i = 0;
	while (i < projectileList.size())
	{
		projectileList[i]->update();
		if (projectileList[i]->deleteMe) {
			delete projectileList[i];
			projectileList.erase(projectileList.begin()+i);
		}
		else
			i++;
	}
}

// draw each projectile
void Shooter::drawProjectiles() {
	for (size_t i = 0; i < projectileList.size(); i++)
	{
		projectileList[i]->draw();
	}
}

void Shooter::checkCollisions(Body * target)
{
	int i = 0;
	while (i < projectileList.size())
	{
		if (projectileList[i]->isAlive && projectileList[i]->checkCollision(target)) {
			makeHit(i, target);
		}
		else {
			i++;
		}
	}
}

void Shooter::makeHit(int projIndex, Body * target)
{
	target->getHitBy(projectileList[projIndex]);
	projectileList[projIndex]->Explode(100);
}

