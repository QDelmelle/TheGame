
#include "Johnny.h"


Johnny::Johnny(int a, int b, int s):Shooter(a, b, s, "Johnny") //a = pos x, b = pos y, s = size, hp = health points
{

	bang.load("sound/Piou.mp3");
	bang.setVolume(1);
	bang.setMultiPlay(true);

	pup.load("sound/pup.mp3");
	pup.setVolume(1);
	pup.setMultiPlay(true);

	health = 100;
	ofLoadImage(texture, "image/Gunman.png");
	roundsLeft = 0;
	rps = 1;
	shotTime = 0;
}

Johnny::~Johnny()
{

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
	Projectile * projectile = new Missile(x, y, size / 4);
	projectile->move(ofVec2f(ofGetMouseX() - x, ofGetMouseY() - y));
	projectileList.push_back(projectile);
	bang.play();
}

void Johnny::draw()
{
	Shooter::draw();
	ofDrawBitmapStringHighlight(std::to_string(health), x+30, y+30);
}

