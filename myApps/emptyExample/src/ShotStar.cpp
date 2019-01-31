#include "ShotStar.h"
#include "ofMain.h"

ShotStar::ShotStar(int a, int b, int s, int tX, int tY, int v):Etoile(a, b, s)
{
	vector = ofVec2f(tX-a, tY-b).normalize()*v;
	birthdate = ofGetElapsedTimef();
}

ShotStar::~ShotStar()
{

}

void ShotStar::update()
{	
	t = ofGetElapsedTimef()-birthdate;
	x = x + t * vector.x;
	y = y + t * vector.y;
}