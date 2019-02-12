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

	int roundsLeft;	// nbre de proj. restants � tirer
	float rps;			// nbre de proj � tirer/sec
	float shotTime;			// time at which the last round was shot
	float numberOfTextureToDisplay;
	float textureTime;		//time at which the last texture was bound

	void update();
	void canarder(int mun, float rps); // tire mun projectiles � rps proj/sec
	void shoot();
	void draw();
	void smile();
	void drawSmile();
};
