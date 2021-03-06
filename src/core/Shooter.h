#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Character.h"
#include "ofMain.h"
#include "Projectile.h"

using namespace std;

// a Character that can throw projectiles!
class Shooter:public Character
{
public:
	Shooter(int, int, int, DataManager* dm, string);
	~Shooter();
	ofSoundPlayer bang; //shooting sound
	std::vector<Projectile*> projectileList; // list of the projectiles this shooter has launched.
	ofTexture shootingTexture; // the texture used when the Shooter is shooting
	
	float shotTime;			// time at which the last round was shot
							//rem : viens de la classe Johnny
	
	void updateProjectiles();

	virtual void shoot() = 0;	// abstract

	void drawProjectiles();
	void checkCollisions(Body* target); //check for collisions between the shooter's
	//projectiles and target Shape.
	virtual void makeHit(int , Body * target); //function used to make collision effects
	// happen bewteen a projectile and the target.

	//override Shape
	virtual void update();
	virtual void draw();

protected:
	void shoot(Projectile*);	// shoot an object and add it to projectiles.

};
