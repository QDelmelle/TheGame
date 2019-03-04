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
	void canarder(int mun, float rps); // tire mun projectiles � rps proj/sec
	int roundsLeft;	// nbre de proj. restants � tirer
	float rps;			// nbre de proj � tirer/sec
	float shotTime;			// time at which the last round was shot

	//@override Shooter
	void update();
	void shoot();
	void draw();
};
