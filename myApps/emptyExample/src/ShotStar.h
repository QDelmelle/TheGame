#pragma once
#include "Etoile.h"
#include "ofMain.h"

class ShotStar :public Etoile
{
public:
	ShotStar(int a, int b, int s, int tX, int tY, int v);
	~ShotStar();
	
	ofVec2f vector;
	void update();
	float birthdate;
	float t;
};