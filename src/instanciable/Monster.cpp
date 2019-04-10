
#include "Monster.h"

Monster::Monster(int a, int b, int s):Character(a, b, s, "Bouboule")
//a = pos x, b = pos y, s = size, hp = health points
{
	ofLoadImage(texture, "image/Phantom.png");
	ofTexture temp;
	ofLoadImage(temp, "image/PhantomBurning3.png");
	burningAnimation.push_back(temp);
	ofLoadImage(temp, "image/PhantomBurning4.png");
	burningAnimation.push_back(temp);
	health = 200;
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
		Character::draw();
		ofDrawBitmapStringHighlight(std::to_string(health), x + 30, y + 30);
	}
}

void Monster::update()
{
	if(isAlive){
		Character::update();
	}
}

