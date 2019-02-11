#include "Missile.h"

Missile::Missile(int a, int b, int s) :Shape(a, b, s){
	ofLoadImage(texture, "image/Missile.png");
	sommets[0] = ofVec2f(cos(PI - PI/6), sin(PI - PI / 6));
	sommets[1] = ofVec2f(cos(PI / 6), sin(PI / 6));
	sommets[2] = ofVec2f(cos(-PI / 6), sin(-PI / 6));
	sommets[3] = ofVec2f(cos(PI / 6 - PI), sin(PI / 6 - PI));
	angle = 0;
}

Missile::~Missile() {

}



void Missile::draw() {
	ofPoint truc[4];
	truc[0] = ofPoint(x + (currentSize*sommets[0].getRotated(angle)).x, y + (currentSize*sommets[0].getRotated(angle)).y);
	truc[1] = ofPoint(x + (currentSize*sommets[1].getRotated(angle)).x, y + (currentSize*sommets[1].getRotated(angle)).y);
	truc[2] = ofPoint(x + (currentSize*sommets[2].getRotated(angle)).x, y + (currentSize*sommets[2].getRotated(angle)).y);
	truc[3] = ofPoint(x + (currentSize*sommets[3].getRotated(angle)).x, y + (currentSize*sommets[3].getRotated(angle)).y);
	texture.draw(truc[0], truc[1], truc[2], truc[3]);
}

void Missile::move(ofVec2f v)
{
	Shape::move(v);
	ofVec2f origin = ofVec2f(1, 0);
	angle = origin.angle(v);
}
