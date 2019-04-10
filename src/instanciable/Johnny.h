#pragma once

#include "../core/Shooter.h"
#include "ofMain.h"
#include "Missile.h"

class Johnny:public Shooter
{
public:
	Johnny(int, int, int);
	~Johnny();

	// new
	void canarder(int mun, float rps); // tire mun projectiles à rps proj/sec
	int roundsLeft;	// nbre de proj. restants à tirer
	float rps;			// nbre de proj à tirer/sec
	

	//@override Shooter
	void update();
	void shoot();
	void draw();

	//override body
	virtual void getHitBy(Projectile * p);
};
