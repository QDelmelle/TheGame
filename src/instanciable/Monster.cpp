
#include "Monster.h"

using namespace effect;

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

/*
	Called by the shooter/attacker
	Projectile "p" gives its effects vector and Monster chooses the elements that affects him
*/
void Monster::getHitBy(Projectile * p)
{
	bool dodged = false;

	/*Boucle peut etre dans un fonction : dans la classe EffectClass?*/
	for (int i = 0; i < p->effects.size(); i++) {
		//check if effect is dodged
		for (int j = 0; j < effectsDodged.size(); j++) {	//remarque : boucle de check est peut etre inutile
			if (p->effects[i] == effectsDodged[j])			//
				dodged = true;								//
		}													//
		// if effect not dodged then apply effect			//
		if (!dodged) {										//
			//apply effect
			switch (p->effects[i]) {
			case PHYSICAL :
				health -= p->dmgOnHit;
				break;
			case BURN:
				EffectClass::burnStartTime = ofGetEllapsedTimef();
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
	if(isAlive){
		Character::update();
		EffectClass::burn(this, hitTime, 3, 10);
	}
}

