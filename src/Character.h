#pragma once

#include "Shooter.h"
#include "ofMain.h"
#include "Missile.h"

class Character:public Shooter
{
public:
	Character(int, int, int, int);
	~Character();

	int health;
	ofTexture texture;
	int roundsLeft;	// nbre de proj. restants à tirer
	float rps;			// nbre de proj à tirer/sec
	float shotTime;			// time at which the last round was shot

	void update();
	void canarder(int mun, float rps); // tire mun projectiles à rps proj/sec
	void shoot();
	void draw();
};
