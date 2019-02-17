#pragma once

#include "../core/Character.h"
#include "ofMain.h"

class Monster:public Character
{
public:
	Monster(int, int, int);
	~Monster();

	float hitTime; // last time this was hit

	// override shape
	virtual void getHitBy(Projectile * other);
	void move(ofVec2f v);

	// override character
	void draw();
	void update();
};
