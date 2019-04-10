#include "Missile.h"

Missile::Missile(int a, int b, int s) :Projectile(a, b, s) {
	ofLoadImage(texture, "image/Missile.png");
	dmgOnHit = 50;
	//ajouter effets dans effects
	effects[PHYSICAL] = 50;
	effects[BURN] = 5;
}