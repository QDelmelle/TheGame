#include "Missile.h"

Missile::Missile(int a, int b, int s) :Projectile(a, b, s){
	ofLoadImage(texture, "image/Missile.png");
	dmgOnHit = 50;
	effects.push_back(1); //effet 1 = explosion
	effects.push_back(2);
}

Missile::~Missile() {

}


