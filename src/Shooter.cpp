#include "Shooter.h"

Shooter::Shooter(int a, int b, int s):Shape(a,b,s)
{
	bang.load("sound/Piou.mp3");
	bang.setVolume(1);
	bang.setMultiPlay(true);
	pup.load("sound/pup.mp3");
	pup.setVolume(1);
	pup.setMultiPlay(true);
}

Shooter::~Shooter()
{

}

void Shooter::shoot()
{
	Shape *projectile = new Shape(x, y, size / 4);
	projectile->move(ofVec2f(ofGetMouseX() - x, ofGetMouseY() - y));
	projectileList.push_back(projectile);
	bang.play();
}

void Shooter::update() {
	Shape::update();
	updateProjectiles();
}

void Shooter::updateProjectiles() {

	int i = 0;
	while (i < projectileList.size()) //update all projectiles
	{
		projectileList[i]->update();
		if (projectileList[i]->isOutTheWindow()) {
			projectileList.erase(projectileList.begin()+i);
			pup.play();
		}
		else
			i++;
	}
}

void Shooter::draw()
{
	Shape::draw();
	drawProjectiles();
}

// draw each projectile
void Shooter::drawProjectiles() {
	//ofDrawBitmapStringHighlight(std::to_string(projectileList.size()), 0, 15);
	for (size_t i = 0; i < projectileList.size(); i++)
	{
		projectileList[i]->draw();
	}
}

