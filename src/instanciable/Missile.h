
#pragma once

#include "../core/Projectile.h"

class Missile :public Projectile {
public:
	Missile(int, int, int, DataManager*);
	~Missile();

	// overrides shape
	void loadData(DataManager*); // loads all textures and sounds from ofApp

	// unique
	
};