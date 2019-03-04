#include "Body.h"
#include "Projectile.h"

Body::Body(int a, int b, int s):Shape(a, b, s)
{
	ofLoadImage(texture, "image/inconnu.png");
}

Body::~Body()
{
}


void Body::getHitBy(Projectile * p)
{
	//aller chercher les effets du projectile et se les appliquer
	// effet 1 et 3
	// résistant à 3
	health -= p->dmgOnHit;
	if (health <= 0) isAlive = false;
}

void Body::draw()
{
	texture.draw(ofPoint(x - currentSize, y - currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x - currentSize, y + currentSize));
}


