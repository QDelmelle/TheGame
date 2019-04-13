#include "Missile.h"

Missile::Missile(int a, int b, int s) :Projectile(a, b, s) {
	//	textures
	ofLoadImage(texture, "image/Missile.png");
	ofTexture temp;
	ofLoadImage(temp, "image/Explosion1.png");
	ExplodeAnimation.push_back(temp);
	ofLoadImage(temp, "image/Explosion2.png");
	ExplodeAnimation.push_back(temp);
	ExplodeImgNbr = 2;

	//	effects
	effects[PHYSICAL] = 50;
	effects[BURN] = 5;
}