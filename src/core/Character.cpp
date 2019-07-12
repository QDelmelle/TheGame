
#include "Character.h"


Character::Character(int a, int b, int s, DataManager* dm, string name):Body(a, b, s, dm)
{
	this->name = name;
}

Character::~Character()
{

}



