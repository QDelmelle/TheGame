#include "Missile.h"

Missile::Missile(int a, int b, int s) :Projectile(a, b, s){
	ofLoadImage(texture, "image/Missile.png");
	dmgOnHit = 50;
	effects.push_back(PHYSICAL);
	effects.push_back(SLOW);
	effects.push_back(BURN);
}

Missile::~Missile() {

}


