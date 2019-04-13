
#include "Johnny.h"


Johnny::Johnny(int a, int b, int s):Shooter(a, b, s, "Johnny") //a = pos x, b = pos y, s = size, hp = health points
{

	bang.load("sound/Piou.mp3");
	bang.setVolume(1);
	bang.setMultiPlay(true);

	health = 100;
	ofLoadImage(texture, "image/Gunman.png");
	ofLoadImage(shootingTexture, "image/GunmanShooting.png");
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

void Johnny::shoot() //redondant => existe déjà dans shooter
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

void Johnny::getHitBy(Projectile * p)
{
	health -= p->effects[PHYSICAL];
	burnDmg = max(burnDmg, p->effects[BURN]);
	burnTicks = 10;
	burnTime = ofGetElapsedTimef();
}

