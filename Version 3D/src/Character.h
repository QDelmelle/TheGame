#pragma once

#include "Shooter.h"
#include "ofMain.h"
#include "Missile.h"
#include "vector"

class Character:public Shooter
{
public:
	Character(int, int, int, int);
	~Character();
	
	int health;

	int action; // action is either SMILE, .....
	std::vector<ofTexture> smileTextures;

	int roundsLeft;	// nbre de proj. restants à tirer
	float rps;			// nbre de proj à tirer/sec
	float shotTime;			// time at which the last round was shot
	float numberOfTextureToDisplay;
	float textureTime;		//time at which the last texture was bound

	void update();
	void canarder(int mun, float rps); // tire mun projectiles à rps proj/sec
	void shoot();
	void draw();
	void smile();
	void drawSmile();
};
