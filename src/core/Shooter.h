#pragma once

#include <vector>
#include "Character.h"
#include "ofMain.h"
#include "Projectile.h"

// a Character that can throw projectiles!
class Shooter:public Character
{
public:
	Shooter(int, int, int, string);
	~Shooter();
	ofSoundPlayer bang; //shooting sound
	ofSoundPlayer pup;	//disappearing sound
	std::vector<Projectile*> projectileList; // list of the projectiles this shooter has launched.
	
	void updateProjectiles();
	virtual void shoot();	// shoot an object and add it to projectiles.
	void drawProjectiles();
	void checkCollisions(Shape* target); //check for collisions between the shooter's
	//projectiles and target Shape.
	virtual bool makeHit(int , Shape * target); //function used to make collision effects
	// happen bewteen a projectile and the target. Returns true if the projectile is destroyed.

	//override Shape
	virtual void update();
	virtual void draw();
};
