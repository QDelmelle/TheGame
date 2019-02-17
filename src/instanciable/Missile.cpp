#include "Missile.h"

Missile::Missile(int a, int b, int s) :Projectile(a, b, s){
	ofLoadImage(texture, "image/Missile.png");
}

Missile::~Missile() {

}

void Missile::affect(Body * target)
{
	target->health -= 10;
}

