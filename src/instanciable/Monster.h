#pragma once

#include "../core/Character.h"
#include "../core/EffectClass.h"
#include "ofMain.h"

class Monster:public Character
{
public:
	//Monster(posX, posY, size)
	Monster(int, int, int);
	~Monster();

	float hitTime; // last time this was hit
	float burnStart;

	// override shape
	void getHitBy(Projectile * p);
	void move(ofVec2f v);

	// override character
	void draw();
	void update();
};
