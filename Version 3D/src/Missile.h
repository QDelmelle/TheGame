
#pragma once

#include "Shape.h"


class Missile :public Shape {
public:
	Missile(int, int, int);
	~Missile();

	ofTexture texture;
	ofVec2f sommets[4];
	int angle;			// orientation par rapport à (1,0)

	void draw();
	void move(ofVec2f);

};