#include "Body.h"
#include "Projectile.h"

Body::Body(int a, int b, int s):Shape(a, b, s)
{
	ofLoadImage(texture, "image/inconnu.png");
	burnTime = ofGetElapsedTimef();
	burnTicks = 0;
	burnDmg = 0;
}

Body::~Body()
{
}


void Body::draw()
{
	texture.draw(ofPoint(x - currentSize, y - currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x - currentSize, y + currentSize));
}

void Body::update()
{
	//TODO : ajouter les autres effets
	Shape::update();
	if (burnTicks > 0 && ofGetElapsedTimef() - burnTime > 1/2.) {
		health -= burnDmg;
		burnTicks--;
		burnTime = ofGetElapsedTimef();
	}
	if (health <= 0) isAlive = false;
}


