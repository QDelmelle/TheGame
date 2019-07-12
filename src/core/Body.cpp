#include "Body.h"
#include "Projectile.h"

Body::Body(int a, int b, int s, DataManager* dm):Shape(a, b, s, dm)
{
	ofLoadImage(texture, "image/inconnu.png");
	status = Utils::ALIVE;

	//	?
	burnTime = 0;// ofGetElapsedTimef();
	burnTicks = 0;
	burnDmg = 0;
	deathAnimTicks = 1;

	setupPersonnalMenu();
}

Body::~Body()
{
}


void Body::setupPersonnalMenu()
{
	menu.setup("Body", "bodySettings.xml", x + 10, y + 10);
	menu.add(guiHealth.setup("Health = ", ofToString(health)));
}


void Body::draw()
{
	ofTexture currentTexture;
	switch (status)
	{
	case Utils::DYING:
		// on a 10 frames => en 2 secondes => 5/sec 
		currentTexture = deathAnimation[(deathAnimation.size() - 1 - deathAnimTicks / 12)];
		deathAnimTicks--;
		break;
	case Utils::ALIVE:
		if (ActiveEffects.find(Utils::BURN) != ActiveEffects.end()) {
			// => on multiplie de le temps par 2*2 (=4) et on prend le modulo 2
			//    pour selectionner la [0] puis la [1] animation
			// Résultat : 2 frames / 0.5 sec
			currentTexture = burningAnimation[((int)((ofGetElapsedTimef() - burnTime) * 4)) % 2];
		}
		else {
			currentTexture = texture;
		}
		break;
	default:
		currentTexture = texture;
		break;
	}
	currentTexture.draw(
		ofPoint(x - currentSize, y - currentSize),
		ofPoint(x + currentSize, y - currentSize),
		ofPoint(x + currentSize, y + currentSize),
		ofPoint(x - currentSize, y + currentSize));

	menu.draw();
}

void Body::update()
{
	switch (status)
	{
	case Utils::ALIVE:
		//TODO : ajouter les autres effets
		Shape::update();
		//recoit burnDmg toutes les 1/2 secondes
		if (ActiveEffects.find(Utils::BURN) != ActiveEffects.end() and
			ofGetElapsedTimef() - burnTime > 1 / 2.) {
			health -= burnDmg;
			burnTicks--;
			burnTime = ofGetElapsedTimef();
			if (burnTicks == 0) {
				ActiveEffects.erase(ActiveEffects.find(Utils::BURN));
			}
		}
		if (health <= 0) status = Utils::DYING;
		break;
	case Utils::DYING:
		if (deathAnimTicks <= 0) {
			status = Utils::DEAD;
			deleteMe = true;
		}
		break;
	case Utils::DEAD:
		break;
	default:
		break;
	}
}


