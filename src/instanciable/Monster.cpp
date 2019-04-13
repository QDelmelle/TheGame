
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

	health = 200;
	punch = false;
	///effectsDodged.push_back(3);
}

Monster::~Monster()
{

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
	if (isAlive) {
		if(!punch) Character::draw();
		ofDrawBitmapStringHighlight(std::to_string(health), x + 30, y + 30);
		if (punch && ofGetMouseX() < x) { //si la souris se trouve à gauche du Monster
			static int i = 1;
			if (i < 100) {
				drawPunch(x - i, y);
				i += 5;
			}
			else if (i >= 100 && 200 > i) {
				drawPunch(x - 100, y);
				i += 1;
			}
			else {
				punch = false;
				i = 1;
			}
		}
	}
}

void Monster::update()
{
	if(isAlive){
		Character::update();
	}
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
		ofPoint(xp - 100, yp - 50),
		ofPoint(xp + 100, yp - 50),
		ofPoint(xp + 100, yp + 50),
		ofPoint(xp - 100, yp + 50));
}

