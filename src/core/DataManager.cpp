#include "DataManager.h"

DataManager::DataManager(int nbTex, int nbSounds)
{
	for (int i = 0; i < nbTex; i++) {
		ofTexture tmp;
		textures.push_back(tmp);
	}
	for (int i = 0; i < nbSounds; i++) {
		ofSoundPlayer tmpp;
		sounds.push_back(tmpp);
	}
}

DataManager::~DataManager()
{
}

void DataManager::loadTextures()
{
	ofLoadImage(textures[0], "image/Missile.png");// ---------------- Missile
	ofLoadImage(textures[1], "image/Explosion1.png");
	ofLoadImage(textures[2], "image/Explosion2.png");
	ofLoadImage(textures[3], "image/RPGuy.png");// ----------------- Johnny
	ofLoadImage(textures[4], "image/RPGuyShooting3.png");
	ofLoadImage(textures[5], "image/Phantom.png");// --------------- Phantom
	ofLoadImage(textures[6], "image/PhantomAngry.png");
	ofLoadImage(textures[7], "image/PhantomBurning3.png");
	ofLoadImage(textures[8], "image/PhantomBurning4.png");
	for (int i = 1; i < 18; i++) {
		ofLoadImage(textures[i+8], "image/PhantomDying"+to_string(i)+".png");
	}
	ofLoadImage(textures[26], "image/PhantomFist.png");
	ofLoadImage(textures[27], "image/PhantomPunch.png");
	ofLoadImage(textures[28], "image/Knight.png");// --------------- Knight
	ofLoadImage(textures[29], "image/KnightSlashing.png");

}

void DataManager::loadSounds()
{
	sounds[0].load("sound/prout.mp3");
	sounds[1].load("sound/pup.mp3");
	sounds[2].load("sound/piou.mp3");


	for (int i = 0; i < sounds.size(); i++) {
		sounds[i].setVolume(1);
		sounds[i].setMultiPlay(true);
	}
}

void DataManager::printTextures()
{
	for (int i = 0; i < textures.size(); i++) {
		textures[i].draw(i*50., 700., 100, 100);
	}
}
