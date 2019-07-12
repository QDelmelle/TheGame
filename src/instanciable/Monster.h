#pragma once

#include "../core/Character.h"
#include "../core/Utils.h"
#include "ofMain.h"

class Monster:public Character
{
public:
	//Monster(posX, posY, size)
	Monster(int, int, int, DataManager*);
	~Monster();

	float hitTime; // last time this was hit
	float burnStart;
	ofTexture fist;
	ofTexture monsterPunch;
	bool punch;
	std::vector<Body*> targets;

	// override shape
	void getHitBy(Projectile * p);
	void move(ofVec2f v);
	void loadData(DataManager *);

	// override character
	void draw();
	void update();

	
	/*
		punch = false => punch = true
	*/
	void attackPunch();
	/*
		Animation de l'attaque au corps à corps
		Appelée dans le Monster::draw()
	*/
	void drawPunch(int, int);

	void meleeHit();

	void addTarget(Body * target);
};
