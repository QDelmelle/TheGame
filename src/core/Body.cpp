#include "Body.h"
#include "Projectile.h"

Body::Body(int a, int b, int s):Shape(a, b, s)
{
	ofLoadImage(texture, "image/inconnu.png");
	burnTime = 0;// ofGetElapsedTimef();
	burnTicks = 0;
	burnDmg = 0;
	deathAnimTicks = 1;
}

Body::~Body()
{
}


void Body::draw()
{
	ofTexture currentTexture;
	if (!isAlive and deathAnimTicks > 0) {
		// on a 10 frames => en 2 secondes => 5/sec 
		currentTexture = deathAnimation[(deathAnimation.size() - 1 - deathAnimTicks / 12)];
		deathAnimTicks--;
		printf("%d deathAnimTicks\n", deathAnimTicks);
	}
	else if (burnTicks > 0) {
		//cout << "((int)(ofGetElapsedTimef() - burnTime) * 2) = " << (int)((ofGetElapsedTimef() - burnTime) * 2) << 
		//	"\n(ofGetElapsedTimef() - burnTime)*2 = " << (ofGetElapsedTimef() - burnTime) * 2 << endl;
		// Etant donné la fonction Body::update
		// et que l'on a 2 textures d'animation
		// => on multiplie de le temps par 2*2 (=4) et on prend le modulo 2
		//    pour selectionner la [0] puis la [1] animation
		// Résultat : 2 frames / 0.5 sec
		currentTexture = burningAnimation[((int)((ofGetElapsedTimef() - burnTime)*4))%2];
	}
	else {
		currentTexture = texture;
	}
	currentTexture.draw(
		ofPoint(x - currentSize, y - currentSize),
		ofPoint(x + currentSize, y - currentSize),
		ofPoint(x + currentSize, y + currentSize),
		ofPoint(x - currentSize, y + currentSize));
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

	if (deathAnimTicks <= 0) {
		deleteMe = true;
		printf("KILL MEEEE !\n");
	}
}


