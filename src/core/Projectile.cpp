#include "Projectile.h"
#include <thread>

Projectile::Projectile(int a, int b, int s) :Shape(a, b, s){
	//ofLoadImage(texture, "image/Projectile.png");
	sommets[0] = ofVec2f(cos(PI - PI/6), sin(PI - PI / 6));
	sommets[1] = ofVec2f(cos(PI / 6), sin(PI / 6));
	sommets[2] = ofVec2f(cos(-PI / 6), sin(-PI / 6));
	sommets[3] = ofVec2f(cos(PI / 6 - PI), sin(PI / 6 - PI));
	angle = 0;
	ExplodeTicks = 0;
	pupTicks = 0;
}

Projectile::~Projectile() {

}

void Projectile::draw() {
	ofPoint truc[4];
	truc[0] = ofPoint(x + (currentSize*sommets[0].getRotated(angle)).x, y + (currentSize*sommets[0].getRotated(angle)).y);
	truc[1] = ofPoint(x + (currentSize*sommets[1].getRotated(angle)).x, y + (currentSize*sommets[1].getRotated(angle)).y);
	truc[2] = ofPoint(x + (currentSize*sommets[2].getRotated(angle)).x, y + (currentSize*sommets[2].getRotated(angle)).y);
	truc[3] = ofPoint(x + (currentSize*sommets[3].getRotated(angle)).x, y + (currentSize*sommets[3].getRotated(angle)).y);
	ofTexture currentTexture;
	if (ExplodeTicks > 0) {
		currentTexture = ExplodeAnimation[(ExplodeTicks/20)%ExplodeImgNbr];
		ExplodeTicks--;
		if (ExplodeTicks == 0)
			deleteMe = true;
	}
	else {
		currentTexture = texture;
	}
	currentTexture.draw(truc[0], truc[1], truc[2], truc[3]);
}

void Projectile::update()
{
	Shape::update();
	if (isOutTheWindow()) {
		if (pupTicks == 0)
			pup.play();
		pupTicks++;
		if (pupTicks > 20) {
			deleteMe = true;
		}
	}
}

void Projectile::move(ofVec2f v)
{
	Shape::move(v);
	ofVec2f origin = ofVec2f(1, 0);
	angle = origin.angle(v);
}

//	make the projectile explode for arg ticks
void Projectile::Explode(int arg)
{
	ExplodeTicks = arg;
	move(ofVec2f(0, 0));
	boom.play();
	currentSize *= 4;
	isAlive = false;
}

bool Projectile::checkCollision(Body * target)
{
	if(target->status == Utils::ALIVE){
		// fancy math right there
		return (pow(x - target->x, 2) + pow(y - target->y, 2) < pow(target->size, 2));
	} else return false;
}