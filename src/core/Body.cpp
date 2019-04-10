#include "Body.h"
#include "Projectile.h"

Body::Body(int a, int b, int s):Shape(a, b, s)
{
	ofLoadImage(texture, "image/inconnu.png");
	burnTime = 0;// ofGetElapsedTimef();
	burnTicks = 0;
	burnDmg = 0;
}

Body::~Body()
{
}


void Body::draw()
{
	if (ofGetElapsedTimef() - burnTime <= 1) {
		cout << "((int)(ofGetElapsedTimef() - burnTime) * 2) = " << (int)((ofGetElapsedTimef() - burnTime) * 2) << 
			"\n(ofGetElapsedTimef() - burnTime)*2 = " << (ofGetElapsedTimef() - burnTime) * 2 << endl;
		// Etant donné la fonction Body::update
		// et que l'on a 2 textures d'animation
		// => on multiplie de le temps par 2*2 (=4) et on prend le modulo 2
		//    pour selectionner la [0] puis la [1] animation
		// Résultat : 2 frames / 0.5 sec
		burningAnimation[((int)((ofGetElapsedTimef() - burnTime)*4))%2].draw(
																ofPoint(x - currentSize, y - currentSize), 
																ofPoint(x + currentSize, y - currentSize), 
																ofPoint(x + currentSize, y + currentSize), 
																ofPoint(x - currentSize, y + currentSize));
	}
	else {
		texture.draw(
			ofPoint(x - currentSize, y - currentSize),
			ofPoint(x + currentSize, y - currentSize),
			ofPoint(x + currentSize, y + currentSize),
			ofPoint(x - currentSize, y + currentSize));
	}
}

void Body::update()
{
	//TODO : ajouter les autres effets
	Shape::update();

	//recoit burnDmg toutes les 1/2 secondes
	if (burnTicks > 0 && ofGetElapsedTimef() - burnTime > 1/2.) {
		health -= burnDmg;
		burnTicks--;
		burnTime = ofGetElapsedTimef();
	}
	if (health <= 0) isAlive = false;
}


