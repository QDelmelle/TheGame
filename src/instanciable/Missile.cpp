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

	//	sounds
	boom.load("sound/pup.mp3");
	boom.setVolume(1);
	boom.setMultiPlay(true);
	pup.load("sound/pup.mp3");
	pup.setVolume(1);
	pup.setMultiPlay(true);
	//	effects
	effects[PHYSICAL] = 50;
	effects[BURN] = 5;
}