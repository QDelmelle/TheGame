#include "..\core\Character.h"

class Knight : public Character 
{
public:
	Knight(int, int, int, string);
	~Knight();

	//override
	void getHitBy(Projectile * p);
};