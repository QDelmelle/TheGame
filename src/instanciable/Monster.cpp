
#include "Monster.h"

Monster::Monster(int a, int b, int s):Character(a, b, s, "Bouboule")
//a = pos x, b = pos y, s = size, hp = health points
{
	//Texture loading
	ofLoadImage(texture, "image/Phantom.png");
	ofTexture temp;
	ofLoadImage(temp, "image/PhantomBurning3.png");
	burningAnimation.push_back(temp);

	ofLoadImage(temp, "image/PhantomBurning4.png");
	burningAnimation.push_back(temp);

	ofLoadImage(fist, "image/PhantomFist.png");
	ofLoadImage(monsterPunch, "image/PhantomPunch.png");

	for (int i = 1; i < 11; i++) {
		ofTexture tempPrime;
		ofLoadImage(tempPrime, "image/PhantomDying"+to_string(i)+".png");
		deathAnimation.push_back(tempPrime);
	}

	deathAnimTicks = 119; //TODO : faire un calcule en fonction de la durée et du nombre de frames
	health = 200;
	punch = false;
	///effectsDodged.push_back(3);
}

Monster::~Monster()
{
	printf("Monster::Destructeur\n");
}

/*
	Called by the shooter/attacker
	Projectile "p" gives its effects vector and Monster chooses the elements that affects him
*/
void Monster::getHitBy(Projectile * p)
{
	printf("%d", health);
	health -= p->effects[PHYSICAL];
	printf("%d", health);
	burnDmg = max(burnDmg, p->effects[BURN]);
	burnTicks = 10;
	burnTime = ofGetElapsedTimef();
}

void Monster::move(ofVec2f v)
{
	Shape::move(v);
}

void Monster::draw()
{
	if(!punch) Character::draw();
	ofDrawBitmapStringHighlight(std::to_string(health), x + 30, y + 30);
	if (punch) { 
		static int i = 16;
		if (i < 40) {
			drawPunch(x - 16, y);
			i += 2;
		}
		else if (i >= 40 && i < 130) {
			drawPunch(x - (i-24), y);
			i += 7;
		}
		else if (i >= 130 && 210 > i) {
			drawPunch(x - 130, y);
			i += 2;
		}
		else {
			Character::draw();
			punch = false;
			i = 15;
		}
	}
	
}

void Monster::update()
{
	Character::update();
}

void Monster::attackPunch()
{
	punch = true;
}

void Monster::drawPunch(int xp,int yp)
{
	monsterPunch.draw(
		ofPoint(x - currentSize, y - currentSize),
		ofPoint(x + currentSize, y - currentSize),
		ofPoint(x + currentSize, y + currentSize),
		ofPoint(x - currentSize, y + currentSize));
	fist.draw(
		ofPoint(xp - 44, yp - 25),
		ofPoint(xp + 44, yp - 25),
		ofPoint(xp + 44, yp + 25),
		ofPoint(xp - 44, yp + 25));
}

