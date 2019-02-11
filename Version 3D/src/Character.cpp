
#include "Character.h"


Character::Character(int a, int b, int s, int hp):Shooter(a, b, s) //a = pos x, b = pos y, s = size, hp = health points
{
	//load texture
	//def HP
	health = hp;
	ofLoadImage(texture, "image/AngryFace.png");
	roundsLeft = 0;
	rps = 1;
	shotTime = 0;
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
}

Character::~Character()
{

}


void Character::update()
{
	if (roundsLeft > 0 && ofGetElapsedTimef()-shotTime > 1/rps) {
		printf("pan");
		shoot();
		shotTime = ofGetElapsedTimef();
		roundsLeft--;
	}
	updateProjectiles();
}

void Character::canarder(int mun, float rps)
{
	roundsLeft = mun;
	this->rps = rps;
}

void Character::shoot()
{
	Shape * projectile = new Missile(x, y, size / 4);
	projectile->move(ofVec2f(ofGetMouseX() - x, -ofGetMouseY() + y));
	projectileList.push_back(projectile);
	bang.play();
}

void Character::draw()
{
	
	//texture.draw(ofPoint(x - currentSize, y + currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x - currentSize, y - currentSize));
	
	texture.bind();
	head.mapTexCoordsFromTexture(texture);
	head.draw();
	texture.unbind();

	drawProjectiles();
}