#include "Etoile.h"
#include "ofMain.h"


Etoile::Etoile(int a, int b, int s)
{
	x = a;
	y = b;
	size = s;
}


Etoile::~Etoile()
{
}

void Etoile::draw() {
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
		ofVertex(x - size, y);
		ofVertex(x, y + size);
		ofVertex(x + size, y);
		ofVertex(x, y - size);
	ofEndShape();
}

void Etoile::set(int a, int b, int s) {
	x = a;
	y = b;
	size = s;
}