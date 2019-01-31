#include "ShootingStar.h"

ShootingStar::ShootingStar(int a, int b, int s):Etoile(a,b,s)
{
	shot = false;
}

ShootingStar::~ShootingStar()
{

}

void ShootingStar::shoot(int targetX, int targetY)
{
	projectile = new ShotStar(x, y, int(size / 4), targetX, targetY, 20);
	shot = true;
}

void ShootingStar::update() {
	if (shot) {
		projectile->update();
	}
}

void ShootingStar::draw()
{
	Etoile::draw();
	if (shot) {
		projectile->draw();
		ofDrawBitmapStringHighlight(std::to_string(projectile->vector.length()), glm::vec3(0, 30, 0));
		ofDrawBitmapStringHighlight(std::to_string(projectile->t), glm::vec3(0, 45, 0));
	}
}