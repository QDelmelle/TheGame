
#include "Monster.h"

Monster::Monster(int a, int b, int s):Character(a, b, s, "Bouboule")
//a = pos x, b = pos y, s = size, hp = health points
{
	ofLoadImage(texture, "image/Phantom.png");
	health = 200;
	effectsDodged.push_back(3);

}

Monster::~Monster()
{

}

void Monster::getHitBy(Projectile * p)
{
	bool dodged = false;
	for (int i = 0; i < p->effects.size(); i++) {
		//check if effect is dodged
		for (int j = 0; j < effectsDodged.size(); j++) {
			if (p->effects[i] == effectsDodged[j])
				dodged = true;
		}
		// if effect not dodged then apply effect
		if (!dodged) {
			//apply effect
			switch (p->effects[i]) {
			case 1 :
				health -= p->dmgOnHit;
				break;
			case 2:
				health -= p->dmgOnHit;
				break;
			default:
				cout << "I resist !" << endl;
			}
		}
		
	}
	
	if (health <= 0) isAlive = false;
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
	if(isAlive)
		Character::update();
}

