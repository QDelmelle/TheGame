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
	int roundsLeft;	// nbre de proj. restants � tirer
	float rps;			// nbre de proj � tirer/sec
	float shotTime;			// time at which the last round was shot

	void update();
	void canarder(int mun, float rps); // tire mun projectiles � rps proj/sec
	void shoot();
	void draw();
};
