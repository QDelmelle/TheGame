
#include "Character.h"

const int NOTHING = 0;
const int SMILE = 1;

Character::Character(int a, int b, int s, int hp):Shooter(a, b, s) //a = pos x, b = pos y, s = size, hp = health points
{
	//load texture
	//def HP
	health = hp;
	roundsLeft = 0;
	rps = 1;
	shotTime = 0;
	action = NOTHING;
	
	//texture setup
	numberOfTextureToDisplay = 1;
	//smileTextures[0].setTextureWrap(GL_REPEAT, GL_REPEAT);
	ofTexture t;
	std::string angryFace;
	for (int i = 0; i < 14; i++) {	//loading the textures
		angryFace = "image/AngryFace" + std::to_string(i) + ".png";
		ofLoadImage(t, angryFace);
		t.setTextureWrap(GL_REPEAT, GL_REPEAT);
		smileTextures.push_back(t);
	}
}

Character::~Character()
{

}


void Character::update()
{
	if (roundsLeft > 0 && ofGetElapsedTimef()-shotTime > 1/rps) {
		shoot();
		shotTime = ofGetElapsedTimef();
		roundsLeft--;
	}
	updateProjectiles();
}

void Character::canarder(int mun, float rps)
{
	roundsLeft = mun;
	this->rps = rps;
}

void Character::shoot()
{
	Shape * projectile = new Missile(x, y, size / 4);
	projectile->move(ofVec2f(ofGetMouseX() - x, -ofGetMouseY() + y));
	projectileList.push_back(projectile);
	bang.play();
}

void Character::draw()
{
	
	ofDrawBitmapString("textures\'s size : "+std::to_string(smileTextures.size()), 0,200,0);
	ofDrawBitmapString("numberOfTextureToDisplay : " + std::to_string(numberOfTextureToDisplay), 0, 230, 0);
	ofDrawBitmapString("action : " + std::to_string(action), 0, 260, 0);
	//texture.draw(ofPoint(x - currentSize, y + currentSize), ofPoint(x + currentSize, y + currentSize), ofPoint(x + currentSize, y - currentSize), ofPoint(x - currentSize, y - currentSize));
	switch (action) {
	case 0:
		smileTextures[0].bind();
		head.mapTexCoordsFromTexture(smileTextures[0]);
		head.draw();
		smileTextures[0].unbind();
		break;
	case SMILE:
		drawSmile();
		break;
	}
	

	drawProjectiles();
}

void Character::smile() {
	numberOfTextureToDisplay = 14;
	action = SMILE;
}

void Character::drawSmile() {

	int i = smileTextures.size() - numberOfTextureToDisplay;
	if (numberOfTextureToDisplay > 1 && ofGetElapsedTimef() - textureTime > (2. / smileTextures.size())) {
		textureTime = ofGetElapsedTimef();
		numberOfTextureToDisplay--;
	}
	if (numberOfTextureToDisplay <= 1) { //stop drawing the smile
		action = 0;
		numberOfTextureToDisplay = 1; //for debug
	}
	smileTextures[i].bind();
	head.mapTexCoordsFromTexture(smileTextures[i]);
	head.draw();
	smileTextures[i].unbind();
}