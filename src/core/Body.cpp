#include "Body.h"

Body::Body(int a, int b, int s):Shape(a, b, s)
{
	ofLoadImage(texture, "image/inconnu.png");
}

Body::~Body()
{
}


void Body::getHitBy(Projectile * P)
{
	P->affect(this);
}

void Body::draw()
{
	texture.draw(ofPoint(x - currentSize, y - currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x - currentSize, y + currentSize));
}


