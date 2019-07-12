#pragma once
#include "ofMain.h"
#include "vector"



class DataManager
{
public:
	DataManager(int, int);
	~DataManager();

	void loadTextures();
	void loadSounds();
	void printTextures();

	vector<ofTexture> textures;
	vector<ofSoundPlayer> sounds;
};