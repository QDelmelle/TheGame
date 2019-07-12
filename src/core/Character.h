#pragma once

#include "ofMain.h"
#include "Body.h"

class Character:public Body
{
public:
	Character(int, int, int, DataManager* dm, string);
	~Character();

	// new
	string name;
	// override Body
};
