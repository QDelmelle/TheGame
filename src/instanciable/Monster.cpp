
#include "Monster.h"

Monster::Monster(int a, int b, int s, DataManager* dm):Character(a, b, s, dm, "Bouboule")
//a = pos x, b = pos y, s = size, hp = health points
{
	loadData(dm);
	deathAnimTicks = 200; //TODO : faire un calcule en fonction de la durée et du nombre de frames
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
	health -= p->effects[Utils::PHYSICAL];
	// pas propre
	ActiveEffects.insert(Utils::BURN);
	burnDmg = max(burnDmg, p->effects[Utils::BURN]);
	burnTicks = 10;
	burnTime = ofGetElapsedTimef();
}

void Monster::move(ofVec2f v)
{
	Shape::move(v);
}

void Monster::loadData(DataManager *dm)
{
	//load textures
	texture = dm->textures[5];
	burningAnimation.push_back(dm->textures[6]);
	burningAnimation.push_back(dm->textures[7]);
	fist = dm->textures[26];
	monsterPunch = dm->textures[27];

	for (int i = 1; i < 18; i++) {
		deathAnimation.push_back(dm->textures[i+8]);
	}
	//load sounds
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
		else if (i >= 130 && i < 137) {
			drawPunch(x - 130, y);
			meleeHit();
			i += 7;
		}
		else if (i >= 137 && 210 > i) {
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

void Monster::addTarget(Body * target)
{
	targets.push_back(target);
	printf("target added\n");
	printf("%d = size, %d = size*size\n", size, size*size);
	
}

void Monster::meleeHit()
{
	for (int i = 0; i < targets.size(); i++) {
		if ((pow(targets[i]->x - x, 2) + pow(targets[i]->y - y, 2)) < size*size*2) {
			targets[i]->health -= 10;
		}
		else
			printf("Raté ! :p\n");
	}
}

