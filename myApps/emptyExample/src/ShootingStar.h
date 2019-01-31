#pragma once
#include "Etoile.h"
#include "ShotStar.h"

class ShootingStar:public Etoile
{
public:
	ShootingStar(int, int, int);
	~ShootingStar();
	ShotStar *projectile;
	void shoot(int, int);
	void update();
	bool shot;
	void draw();
};
